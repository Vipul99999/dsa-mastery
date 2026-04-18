# In-Place Manipulation Pattern

## 🧠 When to use

* Memory optimization needed
* Modify array directly

---

## 👀 Visual

```text
[1,2,3,4] → reverse → [4,3,2,1]
```

---

## 🔧 Template (reverse)

```python
left = 0
right = len(arr) - 1

while left < right:
    arr[left], arr[right] = arr[right], arr[left]
    left += 1
    right -= 1
```

---

## ⚡ Complexity

* Time: O(n)
* Space: O(1)

---

## 🧪 Problems

* Reverse array
* Rotate array
* Move zeroes

---

## ❌ Mistakes

* Overwriting values
* Boundary errors

---

## 🧠 Deep Insight

Saves memory → critical in large-scale systems
