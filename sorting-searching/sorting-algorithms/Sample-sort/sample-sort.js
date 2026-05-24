
function sampleSort(arr, bucketCount) {
  const n = arr.length;

  const samples = [];

  for (let i = 1; i < bucketCount; i++) {
    samples.push(
      arr[Math.floor(i * n / bucketCount)]
    );
  }

  samples.sort((a, b) => a - b);

  const buckets =
    Array.from(
      { length: bucketCount },
      () => []
    );

  for (const num of arr) {
    let bucketIndex = 0;

    while (
      bucketIndex < samples.length &&
      num > samples[bucketIndex]
    ) {
      bucketIndex++;
    }

    buckets[bucketIndex].push(num);
  }

  for (const bucket of buckets) {
    bucket.sort((a, b) => a - b);
  }

  return buckets.flat();
}

const arr = [
  29, 14, 35, 8,
  42, 17, 23, 5, 31
];

console.log("Original array:");
console.log(arr);

const sorted =
  sampleSort(arr, 3);

console.log("\nSorted array:");
console.log(sorted);
