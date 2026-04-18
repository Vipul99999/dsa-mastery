# Binary Search Pattern

## 🧠 When to use

* Sorted arrays
* Search problems
* Monotonic conditions

---

## 👀 Visual

```text
[1,2,3,4,5,6,7]

mid → 4
```

---

## 🔧 Template

```python
left = 0
right = len(arr) - 1

while left <= right:
    mid = (left + right) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        left = mid + 1
    else:
        right = mid - 1
```

---

## ⚡ Complexity

* Time: O(log n)
* Space: O(1)

---

## 🧪 Problems

* Binary Search
* First/Last Position
* Search in Rotated Array

---

## ❌ Mistakes

* Infinite loops
* Mid calculation overflow

---

## 🧠 Deep Insight

Cuts search space in half each step
