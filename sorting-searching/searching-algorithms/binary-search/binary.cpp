#include <iostream>
#include <vector>

// Returns the index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int result = binarySearch(arr, target);
    
    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";
    
    return 0;
}