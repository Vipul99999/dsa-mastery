function mergePathSort(A, B) {
  const result = [];

  let i = 0;
  let j = 0;

  while (i < A.length && j < B.length) {
    if (A[i] <= B[j]) {
      result.push(A[i]);
      i++;
    } else {
      result.push(B[j]);
      j++;
    }
  }

  while (i < A.length) {
    result.push(A[i]);
    i++;
  }

  while (j < B.length) {
    result.push(B[j]);
    j++;
  }

  return result;
}

const A = [1, 4, 7, 10];
const B = [2, 3, 8, 9];

console.log("Array A:");
console.log(A);

console.log("Array B:");
console.log(B);

const merged =
  mergePathSort(A, B);

console.log("\nMerged array:");
console.log(merged);
