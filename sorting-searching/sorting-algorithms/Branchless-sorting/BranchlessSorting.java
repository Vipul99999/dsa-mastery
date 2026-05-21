import java.util.Arrays;

public class BranchlessSorting {

    static int[] branchlessCompareSwap(int a, int b) {
        int minValue = Math.min(a, b);
        int maxValue = Math.max(a, b);

        return new int[]{minValue, maxValue};
    }

    static void branchlessSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int[] values = branchlessCompareSwap(arr[j], arr[j + 1]);

                arr[j] = values[0];
                arr[j + 1] = values[1];
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {8, 3, 7, 4, 9, 2, 6, 1};

        System.out.println("Original array: " + Arrays.toString(arr));

        branchlessSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
```
