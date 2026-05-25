function spreadSort(arr, bucketCount) {
  const minValue = Math.min(...arr);
  const maxValue = Math.max(...arr);

  const range = maxValue - minValue + 1;

  const buckets =
    Array.from(
      { length: bucketCount },
      () => []
    );

  for (const num of arr) {
    let bucketIndex =
      Math.floor(
        ((num - minValue) * bucketCount) / range
      );

    if (bucketIndex === bucketCount) {
      bucketIndex--;
    }

    buckets[bucketIndex].push(num);
  }

  const result = [];

  for (const bucket of buckets) {
    bucket.sort((a, b) => a - b);

    result.push(...bucket);
  }

  return result;
}

const arr = [
  42, 7, 99, 15,
  63, 28, 84
];

console.log("Original array:");
console.log(arr);

const sorted =
  spreadSort(arr, 4);

console.log("\nSorted array:");
console.log(sorted);
