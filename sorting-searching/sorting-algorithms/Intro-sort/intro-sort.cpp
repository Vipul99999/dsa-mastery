#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INSERTION_SORT_THRESHOLD = 16;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void heapSort(vector<int>& arr, int low, int high) {
    make_heap(arr.begin() + low, arr.begin() + high + 1);
    sort_heap(arr.begin() + low, arr.begin() + high + 1);
}

void introSortUtil(
    vector<int>& arr,
    int low,
    int high,
    int depthLimit
) {
    int size = high - low + 1;

    if (size <= INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, low, high);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, low, high);
        return;
    }

    int pivotIndex = partition(arr, low, high);

    introSortUtil(
        arr,
        low,
        pivotIndex - 1,
        depthLimit - 1
    );

    introSortUtil(
        arr,
        pivotIndex + 1,
        high,
        depthLimit - 1
    );
}

void introSort(vector<int>& arr) {
    int depthLimit = 2 * log(arr.size());

    introSortUtil(
        arr,
        0,
        arr.size() - 1,
        depthLimit
    );
}

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {
        8, 3, 7, 4,
        9, 2, 6, 1
    };

    cout << "Original array:\n";
    printArray(arr);

    introSort(arr);

    cout << "\nSorted array:\n";
    printArray(arr);

    return 0;
}
