from typing import List

def fibonacci_search(arr: List[int], target: int) -> int:
    """Returns the index of target if found, else -1.
    PRECONDITION: arr must be sorted in ascending order."""
    n = len(arr)
    if n == 0:
        return -1

    # Initialize Fibonacci numbers
    fib_mm2 = 0  # (m-2)'th Fibonacci
    fib_mm1 = 1  # (m-1)'th Fibonacci
    fib_m = fib_mm2 + fib_mm1  # m'th Fibonacci

    # Find smallest Fibonacci number >= n
    while fib_m < n:
        fib_mm2, fib_mm1 = fib_mm1, fib_m
        fib_m = fib_mm2 + fib_mm1

    offset = -1

    # Main search loop
    while fib_m > 1:
        i = min(offset + fib_mm2, n - 1)

        if arr[i] < target:
            fib_m, fib_mm1, fib_mm2 = fib_mm1, fib_mm2, fib_m - fib_mm1
            offset = i
        elif arr[i] > target:
            fib_m, fib_mm1, fib_mm2 = fib_mm2, fib_mm1 - fib_mm2, fib_m - (fib_mm1 - fib_mm2)
        else:
            return i

    # Check last remaining element
    if fib_mm1 and arr[offset + 1] == target:
        return offset + 1

    return -1

if __name__ == "__main__":
    arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    target = 23
    result = fibonacci_search(arr, target)

    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found.")