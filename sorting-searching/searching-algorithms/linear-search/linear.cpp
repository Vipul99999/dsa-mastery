#include <iostream>
#include <vector>

// Returns the index of target if found, else -1
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {10, 23, 45, 7, 89, 12};
    int target = 89;
    int result = linearSearch(arr, target);
    
    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";
    
    return 0;
}