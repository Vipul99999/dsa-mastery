```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <immintrin.h>
using namespace std;

const int BLOCK_SIZE = 8;

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

void sortBlockWithSIMDStyle(vector<int>& arr, int start, int end) {
    int length = end - start;

    if (length == BLOCK_SIZE) {
        __m256i values = _mm256_loadu_si256((__m256i*)&arr[start]);

        alignas(32) int temp[BLOCK_SIZE];
        _mm256_store_si256((__m256i*)temp, values);

        sort(temp, temp + BLOCK_SIZE);

        values = _mm256_load_si256((__m256i*)temp);
        _mm256_storeu_si256((__m256i*)&arr[start], values);
    } else {
        sort(arr.begin() + start, arr.begin() + end);
    }
}

vector<int> mergeTwoSortedArrays(const vector<int>& left, const vector<int>& right) {
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

void simdSorting(vector<int>& arr) {
    vector<vector<int>> sortedBlocks;

    for (int i = 0; i < arr.size(); i += BLOCK_SIZE) {
        int end = min(i + BLOCK_SIZE, (int)arr.size());

        sortBlockWithSIMDStyle(arr, i, end);

        vector<int> block(arr.begin() + i, arr.begin() + end);
        sortedBlocks.push_back(block);
    }

    while (sortedBlocks.size() > 1) {
        vector<vector<int>> mergedBlocks;

        for (int i = 0; i < sortedBlocks.size(); i += 2) {
            if (i + 1 < sortedBlocks.size()) {
                mergedBlocks.push_back(
                    mergeTwoSortedArrays(sortedBlocks[i], sortedBlocks[i + 1])
                );
            } else {
                mergedBlocks.push_back(sortedBlocks[i]);
            }
        }

        sortedBlocks = mergedBlocks;
    }

    if (!sortedBlocks.empty()) {
        arr = sortedBlocks[0];
    }
}

int main() {
    vector<int> arr = {8, 3, 7, 4, 9, 2, 6, 1, 10, 5, 12, 11};

    cout << "Original array: ";
    printArray(arr);

    simdSorting(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
