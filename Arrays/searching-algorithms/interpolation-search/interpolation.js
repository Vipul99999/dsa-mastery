/**
 * Returns the index of target if found, else -1
 * PRECONDITION: arr must be sorted in ascending order
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function interpolationSearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low === high) {
            return arr[low] === target ? low : -1;
        }

        if (arr[high] === arr[low]) {
            return arr[low] === target ? low : -1;
        }

        // Interpolation formula
        const pos = Math.floor(low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));

        if (arr[pos] === target) return pos;
        else if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

// Example Usage
const arr = [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47];
const target = 18;
const result = interpolationSearch(arr, target);

if (result !== -1) {
    console.log(`Element found at index: ${result}`);
} else {
    console.log("Element not found.");
}