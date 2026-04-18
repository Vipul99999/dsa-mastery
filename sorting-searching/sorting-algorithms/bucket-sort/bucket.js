function bucketSort(arr) {
  const n = arr.length;
  const buckets = Array.from({ length: n }, () => []);

  for (const num of arr) {
    const index = Math.min(n - 1, Math.floor(num * n));
    buckets[index].push(num);
  }

  for (const bucket of buckets) {
    bucket.sort((a, b) => a - b);
  }

  let k = 0;
  for (const bucket of buckets) {
    for (const num of bucket) {
      arr[k++] = num;
    }
  }

  return arr;
}

const arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68];
console.log(bucketSort(arr));