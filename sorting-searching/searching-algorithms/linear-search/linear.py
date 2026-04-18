from typing import List

def linear_search(arr: List[int], target: int) -> int:
    """Returns the index of target if found, else -1."""
    for i, val in enumerate(arr):
        if val == target:
            return i
    return -1

if __name__ == "__main__":
    arr = [10, 23, 45, 7, 89, 12]
    target = 89
    result = linear_search(arr, target)
    
    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found.")