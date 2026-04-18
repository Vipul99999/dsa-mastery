#include <iostream>
#include <vector>

// Returns index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int interpolationSearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // If only one element remains
        if (low == high) {
            return (arr[low] == target) ? low : -1;
        }

        // Prevent division by zero
        if (arr[high] == arr[low]) {
            return (arr[low] == target) ? low : -1;
        }

        // Interpolation formula
        int pos = low + static_cast<int>(
            ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low])
        );

        if (arr[pos] == target) return pos;
        else if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18;
    int result = interpolationSearch(arr, target);

    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";

    return 0;
}