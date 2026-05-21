function branchlessCompareSwap(a, b) {
  const minValue = Math.min(a, b);
  const maxValue = Math.max(a, b);

  return [minValue, maxValue];
}

function branchlessSort(arr) {
  const result = [...arr];

  for (let i = 0; i < result.length - 1; i++) {
    for (let j = 0; j < result.length - i - 1; j++) {
      [result[j], result[j + 1]] =
        branchlessCompareSwap(result[j], result[j + 1]);
    }
  }

  return result;
}

const arr = [8, 3, 7, 4, 9, 2, 6, 1];

console.log("Original array:", arr);

const sortedArray = branchlessSort(arr);

console.log("Sorted array:", sortedArray);
