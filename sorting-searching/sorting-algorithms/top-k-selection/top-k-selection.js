class MinHeap {
  constructor() {
    this.heap = [];
  }

  size() {
    return this.heap.length;
  }

  peek() {
    return this.heap[0];
  }

  push(value) {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop() {
    if (this.heap.length === 1) {
      return this.heap.pop();
    }

    const root = this.heap[0];
    this.heap[0] = this.heap.pop();

    this.heapifyDown();

    return root;
  }

  heapifyUp() {
    let index = this.heap.length - 1;

    while (index > 0) {
      let parent = Math.floor((index - 1) / 2);

      if (this.heap[parent] <= this.heap[index]) {
        break;
      }

      [this.heap[parent], this.heap[index]] =
        [this.heap[index], this.heap[parent]];

      index = parent;
    }
  }

  heapifyDown() {
    let index = 0;

    while (true) {
      let smallest = index;

      let left = 2 * index + 1;
      let right = 2 * index + 2;

      if (left < this.heap.length &&
          this.heap[left] < this.heap[smallest]) {
        smallest = left;
      }

      if (right < this.heap.length &&
          this.heap[right] < this.heap[smallest]) {
        smallest = right;
      }

      if (smallest === index) {
        break;
      }

      [this.heap[index], this.heap[smallest]] =
        [this.heap[smallest], this.heap[index]];

      index = smallest;
    }
  }
}

function topKLargest(arr, k) {
  const minHeap = new MinHeap();

  for (const num of arr) {
    if (minHeap.size() < k) {
      minHeap.push(num);
    }
    else if (num > minHeap.peek()) {
      minHeap.pop();
      minHeap.push(num);
    }
  }

  const result = [];

  while (minHeap.size() > 0) {
    result.push(minHeap.pop());
  }

  result.sort((a, b) => b - a);

  return result;
}

const arr = [12, 5, 7, 19, 3, 25, 8];
const k = 3;

const result = topKLargest(arr, k);

console.log(`Top ${k} largest elements:`, result);
