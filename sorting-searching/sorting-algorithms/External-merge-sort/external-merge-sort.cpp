#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

const int CHUNK_SIZE = 4;

void createSortedRuns(const string& inputFile) {
    ifstream input(inputFile);

    vector<int> chunk;
    int value;
    int runIndex = 0;

    while (input >> value) {
        chunk.push_back(value);

        if (chunk.size() == CHUNK_SIZE) {
            sort(chunk.begin(), chunk.end());

            ofstream runFile("run" + to_string(runIndex) + ".txt");

            for (int num : chunk) {
                runFile << num << " ";
            }

            runFile.close();

            chunk.clear();
            runIndex++;
        }
    }

    if (!chunk.empty()) {
        sort(chunk.begin(), chunk.end());

        ofstream runFile("run" + to_string(runIndex) + ".txt");

        for (int num : chunk) {
            runFile << num << " ";
        }

        runFile.close();
    }

    input.close();
}

void mergeRuns(int totalRuns, const string& outputFile) {
    vector<ifstream> runFiles(totalRuns);

    for (int i = 0; i < totalRuns; i++) {
        runFiles[i].open("run" + to_string(i) + ".txt");
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    for (int i = 0; i < totalRuns; i++) {
        int value;

        if (runFiles[i] >> value) {
            minHeap.push({value, i});
        }
    }

    ofstream output(outputFile);

    while (!minHeap.empty()) {
        auto smallest = minHeap.top();
        minHeap.pop();

        int value = smallest.first;
        int fileIndex = smallest.second;

        output << value << " ";

        if (runFiles[fileIndex] >> value) {
            minHeap.push({value, fileIndex});
        }
    }

    output.close();

    for (auto& file : runFiles) {
        file.close();
    }
}

int main() {
    ofstream input("input.txt");

    input << "8 3 7 4 9 2 6 1";

    input.close();

    createSortedRuns("input.txt");

    mergeRuns(2, "sorted_output.txt");

    cout << "External Merge Sort completed.\n";
    cout << "Check sorted_output.txt\n";

    return 0;
}
