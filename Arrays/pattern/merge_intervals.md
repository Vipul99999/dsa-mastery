# Merge Intervals Pattern

## 🧠 When to use

* Overlapping intervals
* Scheduling problems

---

## 👀 Visual

```text
[1,3] [2,6] → merge → [1,6]
```

---

## 🔧 Template

```python
intervals.sort(key=lambda x: x[0])

merged = []

for interval in intervals:
    if not merged or merged[-1][1] < interval[0]:
        merged.append(interval)
    else:
        merged[-1][1] = max(merged[-1][1], interval[1])
```

---

## ⚡ Complexity

* Time: O(n log n)
* Space: O(n)

---

## 🧪 Problems

* Merge Intervals
* Insert Interval
* Meeting Rooms

---

## ❌ Mistakes

* Not sorting first
* Wrong overlap condition

---

## 🧠 Deep Insight

Sorting converts chaos → structured merging
