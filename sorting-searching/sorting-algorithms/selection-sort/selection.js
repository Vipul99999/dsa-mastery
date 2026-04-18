function selectionSort(arr) {
  const n = arr.length;

  for (let i = 0; i < n; i++) {
    let minIndex = i;

    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
  }

  return arr;
}

const arr = [64, 25, 12, 22, 11];
console.log("Original:", arr);
selectionSort(arr);
console.log("Sorted:", arr);