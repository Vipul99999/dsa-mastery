function dualPivotQuickSort(arr, low = 0, high = arr.length - 1) {
  if (low < high) {
    const [leftPivotIndex, rightPivotIndex] = partition(arr, low, high);

    dualPivotQuickSort(arr, low, leftPivotIndex - 1);
    dualPivotQuickSort(arr, leftPivotIndex + 1, rightPivotIndex - 1);
    dualPivotQuickSort(arr, rightPivotIndex + 1, high);
  }

  return arr;
}

function partition(arr, low, high) {
  if (arr[low] > arr[high]) {
    swap(arr, low, high);
  }

  const leftPivot = arr[low];
  const rightPivot = arr[high];

  let less = low + 1;
  let greater = high - 1;
  let current = less;

  while (current <= greater) {
    if (arr[current] < leftPivot) {
      swap(arr, current, less);
      less++;
    } else if (arr[current] > rightPivot) {
      while (arr[greater] > rightPivot && current < greater) {
        greater--;
      }

      swap(arr, current, greater);
      greater--;

      if (arr[current] < leftPivot) {
        swap(arr, current, less);
        less++;
      }
    }

    current++;
  }

  less--;
  greater++;

  swap(arr, low, less);
  swap(arr, high, greater);

  return [less, greater];
}

function swap(arr, i, j) {
  [arr[i], arr[j]] = [arr[j], arr[i]];
}

const arr = [24, 8, 42, 75, 29, 77, 38, 57];

console.log("Original array:", arr);
dualPivotQuickSort(arr);
console.log("Sorted array:", arr);
