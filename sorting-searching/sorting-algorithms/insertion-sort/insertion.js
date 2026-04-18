function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    const key = arr[i];
    let j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }

  return arr;
}

const arr = [5, 3, 4, 1, 2];
console.log("Original:", arr);
insertionSort(arr);
console.log("Sorted:", arr);