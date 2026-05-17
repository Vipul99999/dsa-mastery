#include <iostream>
#include <vector>
using namespace std;

void swapValues(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

pair<int, int> partition(vector<int>& arr, int low, int high) {
    if (arr[low] > arr[high]) {
        swapValues(arr, low, high);
    }

    int leftPivot = arr[low];
    int rightPivot = arr[high];

    int less = low + 1;
    int greater = high - 1;
    int current = less;

    while (current <= greater) {
        if (arr[current] < leftPivot) {
            swapValues(arr, current, less);
            less++;
        } 
        else if (arr[current] > rightPivot) {
            while (arr[greater] > rightPivot && current < greater) {
                greater--;
            }

            swapValues(arr, current, greater);
            greater--;

            if (arr[current] < leftPivot) {
                swapValues(arr, current, less);
                less++;
            }
        }

        current++;
    }

    less--;
    greater++;

    swapValues(arr, low, less);
    swapValues(arr, high, greater);

    return {less, greater};
}

void dualPivotQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        pair<int, int> pivots = partition(arr, low, high);

        int leftPivotIndex = pivots.first;
        int rightPivotIndex = pivots.second;

        dualPivotQuickSort(arr, low, leftPivotIndex - 1);
        dualPivotQuickSort(arr, leftPivotIndex + 1, rightPivotIndex - 1);
        dualPivotQuickSort(arr, rightPivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {24, 8, 42, 75, 29, 77, 38, 57};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    dualPivotQuickSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
