import heapq

def top_k_largest(arr, k):
    min_heap = []

    for num in arr:
        if len(min_heap) < k:
            heapq.heappush(min_heap, num)

        elif num > min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, num)

    result = sorted(min_heap, reverse=True)

    return result


arr = [12, 5, 7, 19, 3, 25, 8]
k = 3

result = top_k_largest(arr, k)

print(f"Top {k} largest elements:", result)
