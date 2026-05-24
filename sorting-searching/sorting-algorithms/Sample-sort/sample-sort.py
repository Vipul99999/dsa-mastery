
def sample_sort(arr, bucket_count):
    n = len(arr)

    samples = []

    for i in range(1, bucket_count):
        samples.append(
            arr[(i * n) // bucket_count]
        )

    samples.sort()

    buckets = [[] for _ in range(bucket_count)]

    for num in arr:
        bucket_index = 0

        while (
            bucket_index < len(samples)
            and num > samples[bucket_index]
        ):
            bucket_index += 1

        buckets[bucket_index].append(num)

    for bucket in buckets:
        bucket.sort()

    result = []

    for bucket in buckets:
        result.extend(bucket)

    return result


arr = [
    29, 14, 35, 8,
    42, 17, 23, 5, 31
]

print("Original array:")
print(arr)

sorted_array = sample_sort(arr, 3)

print("\nSorted array:")
print(sorted_array)
