/**
 * Returns the index of target if found, else -1
 * PRECONDITION: arr must be sorted in ascending order
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid = Math.floor(left + (right - left) / 2);
        if (arr[mid] === target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Example Usage
const arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];
const target = 23;
const result = binarySearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}