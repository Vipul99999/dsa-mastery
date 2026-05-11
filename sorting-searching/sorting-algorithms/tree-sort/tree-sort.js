class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

function insert(root, value) {
  if (root === null) {
    return new Node(value);
  }

  if (value < root.value) {
    root.left = insert(root.left, value);
  } else {
    root.right = insert(root.right, value);
  }

  return root;
}

function inorder(root, result) {
  if (root === null) return;

  inorder(root.left, result);
  result.push(root.value);
  inorder(root.right, result);
}

function treeSort(arr) {
  let root = null;

  for (const value of arr) {
    root = insert(root, value);
  }

  const result = [];
  inorder(root, result);

  return result;
}

const arr = [5, 3, 7, 2, 4, 6, 8];
console.log("Original:", arr);
console.log("Sorted:", treeSort(arr));
