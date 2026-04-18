from typing import List

class BlockSearch:
    def __init__(self, arr: List[int]):
        """Preprocesses array into blocks with an index table."""
        self.arr = arr
        self.n = len(arr)
        if self.n == 0:
            self.block_size = 0
            self.index_table = []
            return

        self.block_size = int(self.n ** 0.5)
        self.index_table = [arr[i] for i in range(0, self.n, self.block_size)]

    def search(self, target: int) -> int:
        """Searches using index table + linear block scan. O(√n) time."""
        if self.n == 0:
            return -1

        # 1. Find correct block
        block_idx = 0
        while block_idx < len(self.index_table) and self.index_table[block_idx] <= target:
            block_idx += 1
        block_idx -= 1

        # 2. Search within block
        start = block_idx * self.block_size
        end = min(start + self.block_size, self.n)

        for i in range(start, end):
            if self.arr[i] == target:
                return i
        return -1

if __name__ == "__main__":
    arr = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65]
    bs = BlockSearch(arr)

    print(f"Index of 40: {bs.search(40)}")
    print(f"Index of 99: {bs.search(99)}")