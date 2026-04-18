#include <iostream>
#include <vector>
#include <algorithm>

// Returns index of target if found, else -1
// PRECONDITION: arr must be sorted in ascending order
int fibonacciSearch(const std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());
    if (n == 0) return -1;

    // Initialize Fibonacci numbers
    int fibMMm2 = 0; // (m-2)'th Fibonacci
    int fibMMm1 = 1; // (m-1)'th Fibonacci
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    // Find smallest Fibonacci number >= n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    // Main search loop
    while (fibM > 1) {
        int i = std::min(offset + fibMMm2, n - 1);

        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    // Check the last remaining element
    if (fibMMm1 && arr[offset + 1] == target)
        return offset + 1;

    return -1;
}

int main() {
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int result = fibonacciSearch(arr, target);

    if (result != -1)
        std::cout << "Element found at index: " << result << "\n";
    else
        std::cout << "Element not found.\n";

    return 0;
}