const INSERTION_SORT_THRESHOLD = 16;

function insertionSort(arr, left, right) {
  for (let i = left + 1; i <= right; i++) {
    const key = arr[i];

    let j = i - 1;

    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

function partition(arr, low, high) {
  const pivot = arr[high];

  let i = low - 1;

  for (let j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;

      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }

  [arr[i + 1], arr[high]] =
    [arr[high], arr[i + 1]];

  return i + 1;
}

function heapSortSection(arr, low, high) {
  const section = arr
    .slice(low, high + 1)
    .sort((a, b) => a - b);

  for (let i = low; i <= high; i++) {
    arr[i] = section[i - low];
  }
}

function introSortUtil(
  arr,
  low,
  high,
  depthLimit
) {
  const size = high - low + 1;

  if (size <= INSERTION_SORT_THRESHOLD) {
    insertionSort(arr, low, high);
    return;
  }

  if (depthLimit === 0) {
    heapSortSection(arr, low, high);
    return;
  }

  const pivotIndex =
    partition(arr, low, high);

  introSortUtil(
    arr,
    low,
    pivotIndex - 1,
    depthLimit - 1
  );

  introSortUtil(
    arr,
    pivotIndex + 1,
    high,
    depthLimit - 1
  );
}

function introSort(arr) {
  const depthLimit =
    2 * Math.floor(Math.log2(arr.length));

  introSortUtil(
    arr,
    0,
    arr.length - 1,
    depthLimit
  );
}

const arr = [
  8, 3, 7, 4,
  9, 2, 6, 1
];

console.log("Original array:");
console.log(arr);

introSort(arr);

console.log("\nSorted array:");
console.log(arr);
