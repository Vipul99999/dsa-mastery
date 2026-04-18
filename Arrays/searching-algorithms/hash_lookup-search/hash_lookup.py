from typing import List, Optional

class HashLookup:
    def __init__(self, arr: List[int]):
        """Preprocesses array in O(n) time. Stores first occurrence of each value."""
        self.table: dict[int, int] = {}
        for i, val in enumerate(arr):
            if val not in self.table:  # Keeps first occurrence index
                self.table[val] = i

    def search(self, target: int) -> Optional[int]:
        """Average O(1) lookup time."""
        return self.table.get(target, -1)

if __name__ == "__main__":
    arr = [42, 17, 89, 17, 5, 33, 91, 22]
    lookup = HashLookup(arr)

    print(f"Index of 33: {lookup.search(33)}")
    print(f"Index of 99: {lookup.search(99)}")