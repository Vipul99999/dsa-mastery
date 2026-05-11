class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def insert(root, value):
    if root is None:
        return Node(value)

    if value < root.value:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)

    return root


def inorder(root, result):
    if root:
        inorder(root.left, result)
        result.append(root.value)
        inorder(root.right, result)


def tree_sort(arr):
    root = None

    for value in arr:
        root = insert(root, value)

    result = []
    inorder(root, result)
    return result


if __name__ == "__main__":
    arr = [5, 3, 7, 2, 4, 6, 8]
    print("Original:", arr)
    print("Sorted:", tree_sort(arr))
