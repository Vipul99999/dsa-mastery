import java.util.ArrayList;
import java.util.Arrays;

public class TreeSort {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }
    }

    static Node insert(Node root, int value) {
        if (root == null) {
            return new Node(value);
        }

        if (value < root.value) {
            root.left = insert(root.left, value);
        } else {
            root.right = insert(root.right, value);
        }

        return root;
    }

    static void inorder(Node root, ArrayList<Integer> result) {
        if (root == null) return;

        inorder(root.left, result);
        result.add(root.value);
        inorder(root.right, result);
    }

    static ArrayList<Integer> treeSort(int[] arr) {
        Node root = null;

        for (int value : arr) {
            root = insert(root, value);
        }

        ArrayList<Integer> result = new ArrayList<>();
        inorder(root, result);

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 7, 2, 4, 6, 8};

        System.out.println("Original: " + Arrays.toString(arr));
        System.out.println("Sorted: " + treeSort(arr));
    }
}
