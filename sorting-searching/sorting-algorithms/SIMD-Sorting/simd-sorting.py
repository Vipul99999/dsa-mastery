BLOCK_SIZE = 4

def merge_two_sorted_arrays(left, right):
    result = []

    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    while i < len(left):
        result.append(left[i])
        i += 1

    while j < len(right):
        result.append(right[j])
        j += 1

    return result


def simd_style_sort(arr):
    sorted_blocks = []

    for i in range(0, len(arr), BLOCK_SIZE):
        block = arr[i:i + BLOCK_SIZE]
        block.sort()
        sorted_blocks.append(block)

    while len(sorted_blocks) > 1:
        merged_blocks = []

        for i in range(0, len(sorted_blocks), 2):
            if i + 1 < len(sorted_blocks):
                merged_blocks.append(
                    merge_two_sorted_arrays(sorted_blocks[i], sorted_blocks[i + 1])
                )
            else:
                merged_blocks.append(sorted_blocks[i])

        sorted_blocks = merged_blocks

    return sorted_blocks[0] if sorted_blocks else []


arr = [8, 3, 7, 4, 9, 2, 6, 1, 10, 5, 12, 11]

print("Original array:", arr)

sorted_array = simd_style_sort(arr)

print("Sorted array:", sorted_array)
