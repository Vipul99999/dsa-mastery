const BURST_THRESHOLD = 3;

function burstsortRecursive(strings, depth, result) {
  if (strings.length === 0) {
    return;
  }

  if (strings.length <= BURST_THRESHOLD) {
    const sorted = [...strings].sort();

    result.push(...sorted);

    return;
  }

  const buckets = new Map();

  for (const str of strings) {
    const key = depth < str.length ? str[depth] : "\0";

    if (!buckets.has(key)) {
      buckets.set(key, []);
    }

    buckets.get(key).push(str);
  }

  const keys = [...buckets.keys()].sort();

  for (const key of keys) {
    burstsortRecursive(
      buckets.get(key),
      depth + 1,
      result
    );
  }
}

function burstsort(strings) {
  const result = [];

  burstsortRecursive(strings, 0, result);

  return result;
}

const words = [
  "apple",
  "apply",
  "ape",
  "april",
  "banana",
  "band",
  "ball"
];

console.log("Original strings:");
console.log(words);

const sortedWords = burstsort(words);

console.log("\nSorted strings:");
console.log(sortedWords);
