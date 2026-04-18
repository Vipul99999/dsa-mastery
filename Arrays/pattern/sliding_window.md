# Sliding Window Pattern

## 🧠 When to use

* Subarrays / substrings
* Contiguous elements
* Max/min/length problems

---

## 👀 Visual

```text
[1,2,3,4,5]

window:
   [2,3,4]
```

---

## 🔧 Template

```python
left = 0

for right in range(len(arr)):
    # expand window

    while condition_not_valid:
        # shrink window
        left += 1
```

---

## ⚡ Complexity

* Time: O(n)
* Space: O(1)

---

## 🧪 Common Problems

* Longest substring without repeating
* Maximum sum subarray
* Minimum window substring

---

## ❌ Mistakes

* Not shrinking window correctly
* Wrong condition handling

---

## 🧠 Deep Insight

Each element enters & leaves window once → O(n)
