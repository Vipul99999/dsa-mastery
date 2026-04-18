/**
 * Block Search (Indexed Sequential Search)
 * Preprocesses array into blocks with an index table for efficient repeated queries.
 */
class BlockSearch {
    #arr = [];
    #indexTable = [];
    #blockSize = 0;
    #numBlocks = 0;

    /**
     * @param {number[]} inputArr
     */
    constructor(inputArr) {
        this.#arr = inputArr;
        const n = inputArr.length;
        if (n === 0) return;

        this.#blockSize = Math.floor(Math.sqrt(n));
        this.#numBlocks = Math.ceil(n / this.#blockSize);

        // Build index table: stores first element of each block
        for (let i = 0; i < n; i += this.#blockSize) {
            this.#indexTable.push(inputArr[i]);
        }
    }

    /**
     * @param {number} target
     * @returns {number} Index or -1
     */
    search(target) {
        if (this.#arr.length === 0) return -1;

        // 1. Find correct block
        let blockIdx = 0;
        while (blockIdx < this.#indexTable.length && this.#indexTable[blockIdx] <= target) {
            blockIdx++;
        }
        blockIdx--;

        // 2. Search within block
        const start = blockIdx * this.#blockSize;
        const end = Math.min(start + this.#blockSize, this.#arr.length);

        for (let i = start; i < end; i++) {
            if (this.#arr[i] === target) return i;
        }
        return -1;
    }
}

// Example Usage
const arr = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65];
const bs = new BlockSearch(arr);

console.log(`Index of 40: ${bs.search(40)}`);
console.log(`Index of 99: ${bs.search(99)}`);