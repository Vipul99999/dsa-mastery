/**
 * Iterative binary search within a specific range
 */
function _binarySearchRange(arr, left, right, target) {
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] === target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

/**
 * Returns the index of target if found, else -1
 * PRECONDITION: arr must be sorted in ascending order
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function exponentialSearch(arr, target) {
    const n = arr.length;
    if (n === 0) return -1;
    if (arr[0] === target) return 0;

    let i = 1;
    // Double index until out of bounds or value exceeds target
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    return _binarySearchRange(arr, Math.floor(i / 2), Math.min(i, n - 1), target);
}

// Example Usage
const arr = [2, 3, 4, 10, 15, 22, 35, 40, 55, 60, 70, 85, 90];
const target = 40;
const result = exponentialSearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}