#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void branchlessCompareSwap(int &a, int &b) {
    int minValue = min(a, b);
    int maxValue = max(a, b);

    a = minValue;
    b = maxValue;
}

void branchlessSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            branchlessCompareSwap(arr[j], arr[j + 1]);
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {8, 3, 7, 4, 9, 2, 6, 1};

    cout << "Original array: ";
    printArray(arr);

    branchlessSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
