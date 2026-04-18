# Cyclic Sort Pattern

## 🧠 When to use

* Numbers in range 1 to n
* Missing / duplicate numbers

---

## 👀 Visual

```text
[3,1,2]

swap until:
[1,2,3]
```

---

## 🔧 Template

```python
i = 0

while i < len(arr):
    correct = arr[i] - 1

    if arr[i] != arr[correct]:
        arr[i], arr[correct] = arr[correct], arr[i]
    else:
        i += 1
```

---

## ⚡ Complexity

* Time: O(n)
* Space: O(1)

---

## 🧪 Problems

* Missing Number
* Find All Duplicates
* First Missing Positive

---

## ❌ Mistakes

* Infinite swap loops
* Wrong index mapping

---

## 🧠 Deep Insight

Places each element in its correct index
