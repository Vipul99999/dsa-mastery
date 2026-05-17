def dual_pivot_quick_sort(arr, low=0, high=None):
    if high is None:
        high = len(arr) - 1

    if low < high:
        left_pivot_index, right_pivot_index = partition(arr, low, high)

        dual_pivot_quick_sort(arr, low, left_pivot_index - 1)
        dual_pivot_quick_sort(arr, left_pivot_index + 1, right_pivot_index - 1)
        dual_pivot_quick_sort(arr, right_pivot_index + 1, high)

    return arr


def partition(arr, low, high):
    if arr[low] > arr[high]:
        arr[low], arr[high] = arr[high], arr[low]

    left_pivot = arr[low]
    right_pivot = arr[high]

    less = low + 1
    greater = high - 1
    current = less

    while current <= greater:
        if arr[current] < left_pivot:
            arr[current], arr[less] = arr[less], arr[current]
            less += 1

        elif arr[current] > right_pivot:
            while arr[greater] > right_pivot and current < greater:
                greater -= 1

            arr[current], arr[greater] = arr[greater], arr[current]
            greater -= 1

            if arr[current] < left_pivot:
                arr[current], arr[less] = arr[less], arr[current]
                less += 1

        current += 1

    less -= 1
    greater += 1

    arr[low], arr[less] = arr[less], arr[low]
    arr[high], arr[greater] = arr[greater], arr[high]

    return less, greater


arr = [24, 8, 42, 75, 29, 77, 38, 57]

print("Original array:", arr)
dual_pivot_quick_sort(arr)
print("Sorted array:", arr)
