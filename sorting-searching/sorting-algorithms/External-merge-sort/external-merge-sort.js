const fs = require("fs");

const CHUNK_SIZE = 4;

function createSortedRuns(inputFile) {
  const data = fs.readFileSync(inputFile, "utf8")
    .trim()
    .split(/\s+/)
    .map(Number);

  let runIndex = 0;

  for (let i = 0; i < data.length; i += CHUNK_SIZE) {
    const chunk = data
      .slice(i, i + CHUNK_SIZE)
      .sort((a, b) => a - b);

    fs.writeFileSync(
      `run${runIndex}.txt`,
      chunk.join(" ")
    );

    runIndex++;
  }

  return runIndex;
}

function mergeArrays(left, right) {
  const result = [];

  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i++]);
    } else {
      result.push(right[j++]);
    }
  }

  while (i < left.length) {
    result.push(left[i++]);
  }

  while (j < right.length) {
    result.push(right[j++]);
  }

  return result;
}

function mergeRuns(totalRuns, outputFile) {
  let merged = [];

  for (let i = 0; i < totalRuns; i++) {
    const runData = fs.readFileSync(
      `run${i}.txt`,
      "utf8"
    )
      .trim()
      .split(/\s+/)
      .map(Number);

    merged = mergeArrays(merged, runData);
  }

  fs.writeFileSync(outputFile, merged.join(" "));
}

fs.writeFileSync(
  "input.txt",
  "8 3 7 4 9 2 6 1"
);

const totalRuns = createSortedRuns("input.txt");

mergeRuns(totalRuns, "sorted_output.txt");

console.log("External Merge Sort completed.");
console.log("Check sorted_output.txt");
