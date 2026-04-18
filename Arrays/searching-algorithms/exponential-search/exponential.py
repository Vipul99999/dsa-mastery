from typing import List

def _binary_search_range(arr: List[int], left: int, right: int, target: int) -> int:
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def exponential_search(arr: List[int], target: int) -> int:
    """Returns the index of target if found, else -1.
    PRECONDITION: arr must be sorted in ascending order."""
    n = len(arr)
    if n == 0:
        return -1
    if arr[0] == target:
        return 0

    i = 1
    # Double index until boundary exceeded or value surpasses target
    while i < n and arr[i] <= target:
        i *= 2

    return _binary_search_range(arr, i // 2, min(i, n - 1), target)

if __name__ == "__main__":
    arr = [2, 3, 4, 10, 15, 22, 35, 40, 55, 60, 70, 85, 90]
    target = 40
    result = exponential_search(arr, target)

    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found.")