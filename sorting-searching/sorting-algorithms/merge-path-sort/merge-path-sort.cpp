#include <iostream>
#include <vector>
using namespace std;

vector<int> mergePathSort(
    const vector<int>& A,
    const vector<int>& B
) {
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) {
            result.push_back(A[i]);
            i++;
        } else {
            result.push_back(B[j]);
            j++;
        }
    }

    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    return result;
}

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }

    cout << endl;
}

int main() {
    vector<int> A = {1, 4, 7, 10};
    vector<int> B = {2, 3, 8, 9};

    cout << "Array A:\n";
    printArray(A);

    cout << "Array B:\n";
    printArray(B);

    vector<int> merged =
        mergePathSort(A, B);

    cout << "\nMerged array:\n";
    printArray(merged);

    return 0;
}
