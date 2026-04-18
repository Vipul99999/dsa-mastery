#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Returns the index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int jumpSearch(const std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());
    if (n == 0) return -1;

    int step = static_cast<int>(std::sqrt(n));
    int prev = 0;

    // Jump phase
    while (arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += static_cast<int>(std::sqrt(n));
        if (prev >= n) return -1;
    }

    // Linear search phase
    for (int i = prev; i < std::min(step, n); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {0, 1, 3, 4, 6, 7, 9, 11, 12, 14, 15, 18, 20};
    int target = 11;
    int result = jumpSearch(arr, target);

    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";

    return 0;
}