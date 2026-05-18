import heapq

def merge_two_sorted_runs(left, right):
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


def merge_all_runs(runs):
    if not runs:
        return []

    result = runs[0]

    for i in range(1, len(runs)):
        result = merge_two_sorted_runs(result, runs[i])

    return result


def generate_runs(input_array, memory_size):
    runs = []
    current_heap = []
    frozen = []

    index = 0

    while index < len(input_array) and len(current_heap) < memory_size:
        heapq.heappush(current_heap, input_array[index])
        index += 1

    current_run = []
    last_output = float("-inf")

    while current_heap:
        smallest = heapq.heappop(current_heap)

        current_run.append(smallest)
        last_output = smallest

        if index < len(input_array):
            next_value = input_array[index]
            index += 1

            if next_value >= last_output:
                heapq.heappush(current_heap, next_value)
            else:
                frozen.append(next_value)

        if not current_heap:
            runs.append(current_run)
            current_run = []

            for value in frozen:
                heapq.heappush(current_heap, value)

            frozen = []
            last_output = float("-inf")

    return runs


def replacement_selection_sort(input_array, memory_size):
    runs = generate_runs(input_array, memory_size)
    return merge_all_runs(runs)


arr = [6, 2, 8, 3, 9, 1, 7, 4, 5]
memory_size = 3

runs = generate_runs(arr, memory_size)

print("Generated Runs:")
for i, run in enumerate(runs, start=1):
    print(f"Run {i}: {run}")

sorted_array = merge_all_runs(runs)

print("Final Sorted Output:", sorted_array)
