import math
INSERTION_SORT_THRESHOLD = 16

def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        key = arr[i]

        j = i - 1

        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


def partition(arr, low, high):
    pivot = arr[high]

    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1

            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = (
        arr[high],
        arr[i + 1]
    )

    return i + 1


def heap_sort_section(arr, low, high):
    section = sorted(arr[low:high + 1])

    arr[low:high + 1] = section


def introsort_util(
    arr,
    low,
    high,
    depth_limit
):
    size = high - low + 1

    if size <= INSERTION_SORT_THRESHOLD:
        insertion_sort(arr, low, high)
        return

    if depth_limit == 0:
        heap_sort_section(arr, low, high)
        return

    pivot_index = partition(arr, low, high)

    introsort_util(
        arr,
        low,
        pivot_index - 1,
        depth_limit - 1
    )

    introsort_util(
        arr,
        pivot_index + 1,
        high,
        depth_limit - 1
    )


def introsort(arr):
    depth_limit = 2 * int(math.log2(len(arr)))

    introsort_util(
        arr,
        0,
        len(arr) - 1,
        depth_limit
    )


arr = [
    8, 3, 7, 4,
    9, 2, 6, 1
]

print("Original array:")
print(arr)

introsort(arr)

print("\nSorted array:")
print(arr)
