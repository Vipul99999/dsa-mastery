import java.util.Arrays;

public class IntroSort {

    static final int INSERTION_SORT_THRESHOLD = 16;

    static void insertionSort(
        int[] arr,
        int left,
        int right
    ) {
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];

            int j = i - 1;

            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    static int partition(
        int[] arr,
        int low,
        int high
    ) {
        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    static void heapSortSection(
        int[] arr,
        int low,
        int high
    ) {
        int[] section =
            Arrays.copyOfRange(arr, low, high + 1);

        Arrays.sort(section);

        for (int i = low; i <= high; i++) {
            arr[i] = section[i - low];
        }
    }

    static void introSortUtil(
        int[] arr,
        int low,
        int high,
        int depthLimit
    ) {
        int size = high - low + 1;

        if (size <= INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, low, high);
            return;
        }

        if (depthLimit == 0) {
            heapSortSection(arr, low, high);
            return;
        }

        int pivotIndex =
            partition(arr, low, high);

        introSortUtil(
            arr,
            low,
            pivotIndex - 1,
            depthLimit - 1
        );

        introSortUtil(
            arr,
            pivotIndex + 1,
            high,
            depthLimit - 1
        );
    }

    static void introSort(int[] arr) {
        int depthLimit =
            2 * (int)Math.floor(
                Math.log(arr.length) /
                Math.log(2)
            );

        introSortUtil(
            arr,
            0,
            arr.length - 1,
            depthLimit
        );
    }

    public static void main(String[] args) {
        int[] arr = {
            8, 3, 7, 4,
            9, 2, 6, 1
        };

        System.out.println("Original array:");
        System.out.println(Arrays.toString(arr));

        introSort(arr);

        System.out.println("\nSorted array:");
        System.out.println(Arrays.toString(arr));
    }
}
