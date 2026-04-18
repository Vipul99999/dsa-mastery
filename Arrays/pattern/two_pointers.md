# Two Pointers Pattern

## 🧠 When to use

* Sorted arrays
* Finding pairs/triplets
* Opposite direction scanning

---

## 👀 Visual

```text
left →             ← right
[1, 2, 3, 4, 6]
```

---

## 🔧 Template

```python
left = 0
right = len(arr) - 1

while left < right:
    if condition:
        left += 1
    else:
        right -= 1
```

---

## ⚡ Complexity

* Time: O(n)
* Space: O(1)

---

## 🧪 Common Problems

* Two Sum II
* Container With Most Water
* 3Sum

---

## ❌ Mistakes

* Forgetting sorted condition
* Infinite loops
* Wrong pointer movement

---

## 🧠 Deep Insight

You reduce **O(n²)** brute force → **O(n)** by avoiding re-checking pairs.
