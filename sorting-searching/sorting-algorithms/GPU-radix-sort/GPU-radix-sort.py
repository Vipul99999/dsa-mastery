def counting_sort(arr, exp):
    n = len(arr)

    output = [0] * n
    count = [0] * 10

    for num in arr:
        digit = (num // exp) % 10
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        digit = (arr[i] // exp) % 10

        output[count[digit] - 1] = arr[i]
        count[digit] -= 1

    for i in range(n):
        arr[i] = output[i]


def gpu_radix_sort(arr):
    max_val = max(arr)

    exp = 1

    while max_val // exp > 0:
        counting_sort(arr, exp)
        exp *= 10


arr = [170, 45, 75, 90, 802, 24, 2, 66]

gpu_radix_sort(arr)

print("Sorted Array:")
print(arr)
