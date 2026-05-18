import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SIMDSorting {
    static final int BLOCK_SIZE = 4;

    static int[] mergeTwoSortedArrays(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }

        while (i < left.length) {
            result[k++] = left[i++];
        }

        while (j < right.length) {
            result[k++] = right[j++];
        }

        return result;
    }

    static int[] simdStyleSort(int[] arr) {
        List<int[]> sortedBlocks = new ArrayList<>();

        for (int i = 0; i < arr.length; i += BLOCK_SIZE) {
            int end = Math.min(i + BLOCK_SIZE, arr.length);

            int[] block = Arrays.copyOfRange(arr, i, end);
            Arrays.sort(block);

            sortedBlocks.add(block);
        }

        while (sortedBlocks.size() > 1) {
            List<int[]> mergedBlocks = new ArrayList<>();

            for (int i = 0; i < sortedBlocks.size(); i += 2) {
                if (i + 1 < sortedBlocks.size()) {
                    mergedBlocks.add(
                        mergeTwoSortedArrays(sortedBlocks.get(i), sortedBlocks.get(i + 1))
                    );
                } else {
                    mergedBlocks.add(sortedBlocks.get(i));
                }
            }

            sortedBlocks = mergedBlocks;
        }

        return sortedBlocks.isEmpty() ? new int[]{} : sortedBlocks.get(0);
    }

    public static void main(String[] args) {
        int[] arr = {8, 3, 7, 4, 9, 2, 6, 1, 10, 5, 12, 11};

        System.out.println("Original array: " + Arrays.toString(arr));

        int[] sortedArray = simdStyleSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(sortedArray));
    }
}
