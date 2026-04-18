/**
 * Returns the index of target if found, else -1
 * PRECONDITION: arr must be sorted in ascending order
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function fibonacciSearch(arr, target) {
    const n = arr.length;
    if (n === 0) return -1;

    // Initialize Fibonacci numbers
    let fibMMm2 = 0; // (m-2)'th
    let fibMMm1 = 1; // (m-1)'th
    let fibM = fibMMm2 + fibMMm1; // m'th

    // Find smallest fibM >= n
    while (fibM < n) {
        [fibMMm2, fibMMm1] = [fibMMm1, fibM];
        fibM = fibMMm2 + fibMMm1;
    }

    let offset = -1;

    // Main search loop
    while (fibM > 1) {
        const i = Math.min(offset + fibMMm2, n - 1);

        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    // Check last remaining element
    if (fibMMm1 && arr[offset + 1] === target) {
        return offset + 1;
    }

    return -1;
}

// Example Usage
const arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];
const target = 23;
const result = fibonacciSearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}