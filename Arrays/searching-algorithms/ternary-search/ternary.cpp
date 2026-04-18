#include <iostream>
#include <vector>

// Returns index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int ternarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28};
    int target = 16;
    int result = ternarySearch(arr, target);

    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";

    return 0;
}