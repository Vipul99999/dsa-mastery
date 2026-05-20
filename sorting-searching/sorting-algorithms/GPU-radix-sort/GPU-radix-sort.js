function countingSort(arr, exp) {
    const n = arr.length;

    const output = new Array(n).fill(0);
    const count = new Array(10).fill(0);

    for (let i = 0; i < n; i++) {
        const digit = Math.floor(arr[i] / exp) % 10;
        count[digit]++;
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (let i = n - 1; i >= 0; i--) {
        const digit = Math.floor(arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (let i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

function gpuRadixSort(arr) {
    const maxVal = Math.max(...arr);

    for (let exp = 1; Math.floor(maxVal / exp) > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

const arr = [170, 45, 75, 90, 802, 24, 2, 66];

gpuRadixSort(arr);

console.log("Sorted Array:");
console.log(arr);
