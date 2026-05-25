def spread_sort(arr, bucket_count):
    min_value = min(arr)
    max_value = max(arr)

    value_range = max_value - min_value + 1

    buckets = [[] for _ in range(bucket_count)]

    for num in arr:
        bucket_index = (
            (num - min_value)
            * bucket_count
            // value_range
        )

        if bucket_index == bucket_count:
            bucket_index -= 1

        buckets[bucket_index].append(num)

    result = []

    for bucket in buckets:
        bucket.sort()

        result.extend(bucket)

    return result


arr = [
    42, 7, 99, 15,
    63, 28, 84
]

print("Original array:")
print(arr)

sorted_array = spread_sort(arr, 4)

print("\nSorted array:")
print(sorted_array)
