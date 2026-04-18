#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class BlockSearch {
    std::vector<int> arr;
    std::vector<int> indexTable;
    int blockSize;
    int numBlocks;

public:
    explicit BlockSearch(const std::vector<int>& inputArr) : arr(inputArr) {
        int n = arr.size();
        if (n == 0) return;

        blockSize = static_cast<int>(std::sqrt(n));
        numBlocks = (n + blockSize - 1) / blockSize;

        // Build index table: stores the first element of each block
        indexTable.reserve(numBlocks);
        for (int i = 0; i < n; i += blockSize) {
            indexTable.push_back(arr[i]);
        }
    }

    int search(int target) const {
        if (arr.empty()) return -1;

        // 1. Find correct block using index table
        int blockIdx = 0;
        while (blockIdx < numBlocks && indexTable[blockIdx] <= target) {
            blockIdx++;
        }
        blockIdx--; // Step back to the block that might contain target

        // 2. Define search bounds within the identified block
        int start = blockIdx * blockSize;
        int end = std::min(start + blockSize, static_cast<int>(arr.size()));

        // 3. Linear search within the block
        for (int i = start; i < end; ++i) {
            if (arr[i] == target) return i;
        }
        return -1;
    }
};

int main() {
    std::vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65};
    BlockSearch bs(arr);

    std::cout << "Index of 40: " << bs.search(40) << "\n";
    std::cout << "Index of 99: " << bs.search(99) << "\n";

    return 0;
}