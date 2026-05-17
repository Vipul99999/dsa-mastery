import java.util.Arrays;

public class DualPivotQuickSort {

    static void dualPivotQuickSort(int[] arr, int low, int high) {
        if (low < high) {
            int[] pivots = partition(arr, low, high);

            int leftPivotIndex = pivots[0];
            int rightPivotIndex = pivots[1];

            dualPivotQuickSort(arr, low, leftPivotIndex - 1);
            dualPivotQuickSort(arr, leftPivotIndex + 1, rightPivotIndex - 1);
            dualPivotQuickSort(arr, rightPivotIndex + 1, high);
        }
    }

    static int[] partition(int[] arr, int low, int high) {
        if (arr[low] > arr[high]) {
            swap(arr, low, high);
        }

        int leftPivot = arr[low];
        int rightPivot = arr[high];

        int less = low + 1;
        int greater = high - 1;
        int current = less;

        while (current <= greater) {
            if (arr[current] < leftPivot) {
                swap(arr, current, less);
                less++;
            } else if (arr[current] > rightPivot) {
                while (arr[greater] > rightPivot && current < greater) {
                    greater--;
                }

                swap(arr, current, greater);
                greater--;

                if (arr[current] < leftPivot) {
                    swap(arr, current, less);
                    less++;
                }
            }

            current++;
        }

        less--;
        greater++;

        swap(arr, low, less);
        swap(arr, high, greater);

        return new int[]{less, greater};
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {24, 8, 42, 75, 29, 77, 38, 57};

        System.out.println("Original array: " + Arrays.toString(arr));

        dualPivotQuickSort(arr, 0, arr.length - 1);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
