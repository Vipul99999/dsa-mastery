import java.util.Arrays;

public class insertion {
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 4, 1, 2};

        System.out.println("Original: " + Arrays.toString(arr));
        insertionSort(arr);
        System.out.println("Sorted: " + Arrays.toString(arr));
    }
}