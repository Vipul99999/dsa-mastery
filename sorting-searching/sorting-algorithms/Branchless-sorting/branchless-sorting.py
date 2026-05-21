def branchless_compare_swap(a, b):
    min_value = min(a, b)
    max_value = max(a, b)

    return min_value, max_value


def branchless_sort(arr):
    result = arr[:]

    n = len(result)

    for i in range(n - 1):
        for j in range(n - i - 1):
            result[j], result[j + 1] = branchless_compare_swap(
                result[j],
                result[j + 1]
            )

    return result


arr = [8, 3, 7, 4, 9, 2, 6, 1]

print("Original array:", arr)

sorted_array = branchless_sort(arr)

print("Sorted array:", sorted_array)
