#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> mergeTwoSortedRuns(const vector<int>& left, const vector<int>& right) {
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

vector<int> mergeAllRuns(vector<vector<int>>& runs) {
    if (runs.empty()) {
        return {};
    }

    vector<int> result = runs[0];

    for (int i = 1; i < runs.size(); i++) {
        result = mergeTwoSortedRuns(result, runs[i]);
    }

    return result;
}

vector<vector<int>> generateRuns(const vector<int>& input, int memorySize) {
    vector<vector<int>> runs;

    priority_queue<int, vector<int>, greater<int>> currentHeap;
    vector<int> frozen;

    int index = 0;
    int n = input.size();

    while (index < n && currentHeap.size() < memorySize) {
        currentHeap.push(input[index]);
        index++;
    }

    vector<int> currentRun;
    int lastOutput = -1000000000;

    while (!currentHeap.empty()) {
        int smallest = currentHeap.top();
        currentHeap.pop();

        currentRun.push_back(smallest);
        lastOutput = smallest;

        if (index < n) {
            int nextValue = input[index];
            index++;

            if (nextValue >= lastOutput) {
                currentHeap.push(nextValue);
            } else {
                frozen.push_back(nextValue);
            }
        }

        if (currentHeap.empty()) {
            runs.push_back(currentRun);
            currentRun.clear();

            for (int value : frozen) {
                currentHeap.push(value);
            }

            frozen.clear();
            lastOutput = -1000000000;
        }
    }

    return runs;
}

vector<int> replacementSelectionSort(const vector<int>& input, int memorySize) {
    vector<vector<int>> runs = generateRuns(input, memorySize);
    return mergeAllRuns(runs);
}

int main() {
    vector<int> arr = {6, 2, 8, 3, 9, 1, 7, 4, 5};
    int memorySize = 3;

    vector<vector<int>> runs = generateRuns(arr, memorySize);

    cout << "Generated Runs:\n";
    for (int i = 0; i < runs.size(); i++) {
        cout << "Run " << i + 1 << ": ";
        for (int value : runs[i]) {
            cout << value << " ";
        }
        cout << endl;
    }

    vector<int> sortedArray = mergeAllRuns(runs);

    cout << "\nFinal Sorted Output: ";
    for (int value : sortedArray) {
        cout << value << " ";
    }

    return 0;
}
