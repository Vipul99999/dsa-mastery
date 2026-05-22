BURST_THRESHOLD = 3

def burstsort_recursive(strings, depth, result):
    if not strings:
        return

    if len(strings) <= BURST_THRESHOLD:
        result.extend(sorted(strings))
        return

    buckets = {}

    for string in strings:
        key = string[depth] if depth < len(string) else "\0"

        if key not in buckets:
            buckets[key] = []

        buckets[key].append(string)

    for key in sorted(buckets.keys()):
        burstsort_recursive(
            buckets[key],
            depth + 1,
            result
        )


def burstsort(strings):
    result = []

    burstsort_recursive(strings, 0, result)

    return result


words = [
    "apple",
    "apply",
    "ape",
    "april",
    "banana",
    "band",
    "ball"
]

print("Original strings:")
print(words)

sorted_words = burstsort(words)

print("\nSorted strings:")
print(sorted_words)
