#include <iostream>
#include <vector>
#include <algorithm>

// Iterative binary search within a specific range
int binarySearchRange(const std::vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Returns the index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int exponentialSearch(const std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());
    if (n == 0) return -1;
    if (arr[0] == target) return 0;

    int i = 1;
    // Double the index until out of bounds or value exceeds target
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    // Binary search in the identified range [i/2, min(i, n-1)]
    return binarySearchRange(arr, i / 2, std::min(i, n - 1), target);
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 15, 22, 35, 40, 55, 60, 70, 85, 90};
    int target = 40;
    int result = exponentialSearch(arr, target);

    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";

    return 0;
}