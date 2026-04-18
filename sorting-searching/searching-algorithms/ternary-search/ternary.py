from typing import List

def ternary_search(arr: List[int], target: int) -> int:
    """Returns the index of target if found, else -1.
    PRECONDITION: arr must be sorted in ascending order."""
    left, right = 0, len(arr) - 1

    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1

    return -1

if __name__ == "__main__":
    arr = [1, 4, 7, 10, 13, 16, 19, 22, 25, 28]
    target = 16
    result = ternary_search(arr, target)

    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found.")