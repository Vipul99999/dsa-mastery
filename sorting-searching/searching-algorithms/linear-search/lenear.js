/**
 * Returns the index of target if found, else -1
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) return i;
    }
    return -1;
}

// Example Usage
const arr = [10, 23, 45, 7, 89, 12];
const target = 89;
const result = linearSearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}