import math
from typing import List

def jump_search(arr: List[int], target: int) -> int:
    """Returns the index of target if found, else -1.
    PRECONDITION: arr must be sorted in ascending order."""
    n = len(arr)
    if n == 0:
        return -1

    step = int(math.sqrt(n))
    prev = 0

    # Jump phase
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    # Linear search phase
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
    return -1

if __name__ == "__main__":
    arr = [0, 1, 3, 4, 6, 7, 9, 11, 12, 14, 15, 18, 20]
    target = 11
    result = jump_search(arr, target)

    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found.")