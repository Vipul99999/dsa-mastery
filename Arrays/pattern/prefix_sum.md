# Prefix Sum Pattern

## 🧠 When to use

* Range sum queries
* Subarray sum problems

---

## 👀 Visual

```text
arr:    [1, 2, 3, 4]
prefix: [1, 3, 6, 10]
```

---

## 🔧 Formula

[
sum(l, r) = prefix[r] - prefix[l-1]
]

---

## 🔧 Template

```python
prefix = [0] * len(arr)
prefix[0] = arr[0]

for i in range(1, len(arr)):
    prefix[i] = prefix[i-1] + arr[i]
```

---

## ⚡ Complexity

* Build: O(n)
* Query: O(1)

---

## 🧪 Problems

* Subarray Sum Equals K
* Range Sum Query

---

## ❌ Mistakes

* Index errors
* Not handling l=0 case

---

## 🧠 Deep Insight

Turns repeated O(n) work → O(1) queries
