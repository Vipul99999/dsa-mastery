# 02 — Static vs Dynamic Arrays

Arrays come in two major forms:

* **Static arrays**
* **Dynamic arrays**

Understanding the difference explains how languages manage memory.

---

# 1. Static arrays

A static array has fixed size.

Example:

```c
int arr[5];
```

Memory is reserved immediately.

Visual:

```text
┌────┬────┬────┬────┬────┐
│    │    │    │    │    │
└────┴────┴────┴────┴────┘
 size = 5 forever
```

---

## Properties

| Property           | Static |
| ------------------ | ------ |
| Resize             | No     |
| Fast access        | Yes    |
| Predictable memory | Yes    |
| Extra overhead     | None   |

---

# 2. Problem with static arrays

If capacity is exceeded:

```c
arr[5] = 100;
```

You cannot safely store more.

Visual:

```text
Capacity full
┌──┬──┬──┬──┬──┐
│1 │2 │3 │4 │5 │
└──┴──┴──┴──┴──┘
         no room
```

---

# 3. Dynamic arrays

Dynamic arrays can grow.

Examples:

* C++ vector
* Python list
* Java ArrayList
* Rust Vec

Entities:

* C++
* Python
* Java
* Rust

---

# 4. Length vs capacity

Dynamic arrays track:

```text
length   = used elements
capacity = allocated slots
```

Visual:

```text
capacity = 8
length   = 5

┌──┬──┬──┬──┬──┬──┬──┬──┐
│1 │2 │3 │4 │5 │  │  │  │
└──┴──┴──┴──┴──┴──┴──┴──┘
```

---

# 5. Growth process

When full:

Before:

```text
capacity = 4
┌──┬──┬──┬──┐
│1 │2 │3 │4 │
└──┴──┴──┴──┘
```

Allocate larger block:

```text
capacity = 8
┌──┬──┬──┬──┬──┬──┬──┬──┐
│1 │2 │3 │4 │  │  │  │  │
└──┴──┴──┴──┴──┴──┴──┴──┘
```

Copy old elements into new memory.

---

# 6. Typical growth formula

Most dynamic arrays grow by:

$$
new_capacity = old_capacity \times 2
$$

Visual:
new_capacity=old_capacity\times 2

Example:

```text
1 → 2 → 4 → 8 → 16 → 32
```

---

# 7. Why doubling works

Without doubling:

```text
1 → 2 → 3 → 4 → 5 ...
```

Too many reallocations.

With doubling:

```text
1 → 2 → 4 → 8 → 16
```

Fewer copies.

Visual:

```text
Small growth:
copy copy copy copy copy

Doubling:
copy ..... copy ......... copy
```

---

# 8. Hidden cost of resizing

Appending usually cheap:

```python
arr.append(x)
```

But sometimes expensive because:

1. allocate new memory
2. copy elements
3. free old block

Visual:

```text
Old memory
[1][2][3][4]

New memory
[1][2][3][4][ ][ ][ ][ ]
```

---

# 9. Time complexity

| Operation      | Complexity |
| -------------- | ---------- |
| Access         | O(1)       |
| Append average | O(1)       |
| Append resize  | O(n)       |
| Insert middle  | O(n)       |

---

# 10. Memory tradeoff

Dynamic arrays use extra memory.

Example:

```text
length = 5
capacity = 8
unused = 3
```

Visual:

```text
Used:
■■■■■

Unused:
□□□
```

Tradeoff:

* faster appends
* more memory overhead

---

# 11. Fragmentation issue

Large allocations may move memory elsewhere.

Visual:

```text
Old block:
1000 ─────────► [1][2][3][4]

New block:
5000 ─────────► [1][2][3][4][5][ ][ ][ ]
```

Pointers to old memory may become invalid.

Important in low-level languages.

---

# 12. Static vs dynamic comparison

| Feature          | Static | Dynamic      |
| ---------------- | ------ | ------------ |
| Size fixed       | Yes    | No           |
| Memory efficient | Yes    | Less         |
| Flexible         | No     | Yes          |
| Simple           | Yes    | More complex |

---

# 13. Real-world examples

Static:

* embedded systems
* fixed-size buffers
* matrix dimensions known at compile time

Dynamic:

* text editors
* logs
* lists of users
* runtime collections

---

# 14. Key takeaway

Static arrays prioritize:

✔ simplicity
✔ speed
✔ predictability

Dynamic arrays prioritize:

✔ flexibility
✔ scalability
✔ convenience

Core tradeoff:

```text
Predictability vs flexibility
```
