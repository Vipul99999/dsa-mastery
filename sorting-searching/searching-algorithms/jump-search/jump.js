/**
 * Returns the index of target if found, else -1
 * PRECONDITION: arr must be sorted in ascending order
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function jumpSearch(arr, target) {
    const n = arr.length;
    if (n === 0) return -1;

    let step = Math.floor(Math.sqrt(n));
    let prev = 0;

    // Jump phase
    while (arr[Math.min(step, n) - 1] < target) {
        prev = step;
        step += Math.floor(Math.sqrt(n));
        if (prev >= n) return -1;
    }

    // Linear search phase
    for (let i = prev; i < Math.min(step, n); i++) {
        if (arr[i] === target) return i;
    }
    return -1;
}

// Example Usage
const arr = [0, 1, 3, 4, 6, 7, 9, 11, 12, 14, 15, 18, 20];
const target = 11;
const result = jumpSearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}