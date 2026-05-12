
# Tim Sort

Tim Sort is a hybrid stable sorting algorithm derived from Merge Sort and Insertion Sort.

It is designed to perform very well on real-world data because real-world arrays often contain already sorted parts.

Tim Sort is used in:
- Python's built-in `sort()`
- Java's sorting for objects
- Android and many production systems

---

## Idea

Tim Sort breaks the array into small sorted parts called **runs**.

A run is a small portion of the array that is already sorted or made sorted using insertion sort.

Then Tim Sort merges these runs using merge sort logic.

---

## Why Tim Sort?

Normal merge sort always divides the array equally.

Tim Sort is smarter because it checks whether some parts are already sorted.

Example:

```txt
Input:
[1, 2, 3, 7, 8, 4, 5, 6]

Runs:
[1, 2, 3, 7, 8] and [4, 5, 6]

After merge:
[1, 2, 3, 4, 5, 6, 7, 8]
````

---

## Main Steps

### Step 1: Divide into runs

Small chunks are sorted using insertion sort.

```txt
[5, 2, 4, 1, 3, 8, 7, 6]

Run 1: [5, 2, 4, 1] → [1, 2, 4, 5]
Run 2: [3, 8, 7, 6] → [3, 6, 7, 8]
```

### Step 2: Merge sorted runs

```txt
[1, 2, 4, 5] + [3, 6, 7, 8]

Final:
[1, 2, 3, 4, 5, 6, 7, 8]
```

---

## Visual Flow

```txt
Original Array
[5, 2, 4, 1, 3, 8, 7, 6]

Divide into runs
[5, 2, 4, 1] [3, 8, 7, 6]

Sort each run using insertion sort
[1, 2, 4, 5] [3, 6, 7, 8]

Merge runs
[1, 2, 3, 4, 5, 6, 7, 8]
```

---

## Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | O(n)            |
| Average Case | O(n log n)      |
| Worst Case   | O(n log n)      |

## Space Complexity

```txt
O(n)
```

---

## Stability

Tim Sort is stable.

That means equal elements keep their original relative order.

---

## Use Cases

Tim Sort is useful when:

* Data is partially sorted
* Stability is required
* Real-world performance matters
* Sorting objects or records
* Production-level sorting is needed

---

## Advantages

* Very fast on real-world data
* Stable sorting algorithm
* Better than merge sort for partially sorted data
* Better than insertion sort for large data
* Used in real programming languages

---

## Disadvantages

* More complex than basic sorting algorithms
* Uses extra memory
* Harder to implement than merge sort or quick sort

---

## Example

```txt
Input:
[5, 21, 7, 23, 19]

Output:
[5, 7, 19, 21, 23]
```
