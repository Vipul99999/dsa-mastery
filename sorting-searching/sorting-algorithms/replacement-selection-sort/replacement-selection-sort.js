class MinHeap {
  constructor() {
    this.heap = [];
  }

  size() {
    return this.heap.length;
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  push(value) {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop() {
    if (this.isEmpty()) {
      return null;
    }

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
      const parent = Math.floor((index - 1) / 2);

      if (this.heap[parent] <= this.heap[index]) {
        break;
      }

      [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
      index = parent;
    }
  }

  heapifyDown() {
    let index = 0;

    while (true) {
      let smallest = index;
      const left = 2 * index + 1;
      const right = 2 * index + 2;

      if (left < this.heap.length && this.heap[left] < this.heap[smallest]) {
        smallest = left;
      }

      if (right < this.heap.length && this.heap[right] < this.heap[smallest]) {
        smallest = right;
      }

      if (smallest === index) {
        break;
      }

      [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
      index = smallest;
    }
  }
}

function mergeTwoSortedRuns(left, right) {
  const result = [];

  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }

  while (i < left.length) {
    result.push(left[i]);
    i++;
  }

  while (j < right.length) {
    result.push(right[j]);
    j++;
  }

  return result;
}

function mergeAllRuns(runs) {
  if (runs.length === 0) {
    return [];
  }

  let result = runs[0];

  for (let i = 1; i < runs.length; i++) {
    result = mergeTwoSortedRuns(result, runs[i]);
  }

  return result;
}

function generateRuns(inputArray, memorySize) {
  const runs = [];
  const currentHeap = new MinHeap();
  let frozen = [];

  let index = 0;

  while (index < inputArray.length && currentHeap.size() < memorySize) {
    currentHeap.push(inputArray[index]);
    index++;
  }

  let currentRun = [];
  let lastOutput = -Infinity;

  while (!currentHeap.isEmpty()) {
    const smallest = currentHeap.pop();

    currentRun.push(smallest);
    lastOutput = smallest;

    if (index < inputArray.length) {
      const nextValue = inputArray[index];
      index++;

      if (nextValue >= lastOutput) {
        currentHeap.push(nextValue);
      } else {
        frozen.push(nextValue);
      }
    }

    if (currentHeap.isEmpty()) {
      runs.push(currentRun);
      currentRun = [];

      for (const value of frozen) {
        currentHeap.push(value);
      }

      frozen = [];
      lastOutput = -Infinity;
    }
  }

  return runs;
}

function replacementSelectionSort(inputArray, memorySize) {
  const runs = generateRuns(inputArray, memorySize);
  return mergeAllRuns(runs);
}

const arr = [6, 2, 8, 3, 9, 1, 7, 4, 5];
const memorySize = 3;

const runs = generateRuns(arr, memorySize);

console.log("Generated Runs:");
runs.forEach((run, index) => {
  console.log(`Run ${index + 1}:`, run);
});

const sortedArray = mergeAllRuns(runs);

console.log("Final Sorted Output:", sortedArray);
