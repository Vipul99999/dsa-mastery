def merge_path_sort(A, B):
    result = []

    i = 0
    j = 0

    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1

    while i < len(A):
        result.append(A[i])
        i += 1

    while j < len(B):
        result.append(B[j])
        j += 1

    return result


A = [1, 4, 7, 10]
B = [2, 3, 8, 9]

print("Array A:")
print(A)

print("Array B:")
print(B)

merged = merge_path_sort(A, B)

print("\nMerged array:")
print(merged)
