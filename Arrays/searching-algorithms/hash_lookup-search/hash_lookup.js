/**
 * Hash-based lookup structure for repeated O(1) queries
 */
class HashLookup {
    #table = new Map();

    /**
     * Preprocesses array in O(n) time. Stores first occurrence of each value.
     * @param {number[]} arr
     */
    constructor(arr) {
        for (let i = 0; i < arr.length; i++) {
            if (!this.#table.has(arr[i])) {
                this.#table.set(arr[i], i);
            }
        }
    }

    /**
     * Average O(1) lookup time
     * @param {number} target
     * @returns {number} Index or -1 if not found
     */
    search(target) {
        return this.#table.has(target) ? this.#table.get(target) : -1;
    }
}

// Example Usage
const arr = [42, 17, 89, 17, 5, 33, 91, 22];
const lookup = new HashLookup(arr);

console.log(`Index of 33: ${lookup.search(33)}`);
console.log(`Index of 99: ${lookup.search(99)}`);