const BLOCK_SIZE = 4;

function mergeTwoSortedArrays(left, right) {
  const result = [];

  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }

  while (i < left.length) {
    result.push(left[i]);
    i++;
  }

  while (j < right.length) {
    result.push(right[j]);
    j++;
  }

  return result;
}

function simdStyleSort(arr) {
  const sortedBlocks = [];

  for (let i = 0; i < arr.length; i += BLOCK_SIZE) {
    const block = arr.slice(i, i + BLOCK_SIZE);

    block.sort((a, b) => a - b);

    sortedBlocks.push(block);
  }

  while (sortedBlocks.length > 1) {
    const mergedBlocks = [];

    for (let i = 0; i < sortedBlocks.length; i += 2) {
      if (i + 1 < sortedBlocks.length) {
        mergedBlocks.push(
          mergeTwoSortedArrays(sortedBlocks[i], sortedBlocks[i + 1])
        );
      } else {
        mergedBlocks.push(sortedBlocks[i]);
      }
    }

    sortedBlocks.length = 0;
    sortedBlocks.push(...mergedBlocks);
  }

  return sortedBlocks.length > 0 ? sortedBlocks[0] : [];
}

const arr = [8, 3, 7, 4, 9, 2, 6, 1, 10, 5, 12, 11];

console.log("Original array:", arr);

const sortedArray = simdStyleSort(arr);

console.log("Sorted array:", sortedArray);
