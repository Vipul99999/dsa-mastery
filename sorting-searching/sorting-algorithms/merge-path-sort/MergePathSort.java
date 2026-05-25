import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MergePathSort {

    static List<Integer> mergePathSort(
        int[] A,
        int[] B
    ) {
        List<Integer> result =
            new ArrayList<>();

        int i = 0;
        int j = 0;

        while (i < A.length && j < B.length) {
            if (A[i] <= B[j]) {
                result.add(A[i]);
                i++;
            } else {
                result.add(B[j]);
                j++;
            }
        }

        while (i < A.length) {
            result.add(A[i]);
            i++;
        }

        while (j < B.length) {
            result.add(B[j]);
            j++;
        }

        return result;
    }

    public static void main(String[] args) {
        int[] A = {1, 4, 7, 10};
        int[] B = {2, 3, 8, 9};

        System.out.println("Array A:");
        System.out.println(
            Arrays.toString(A)
        );

        System.out.println("Array B:");
        System.out.println(
            Arrays.toString(B)
        );

        List<Integer> merged =
            mergePathSort(A, B);

        System.out.println(
            "\nMerged array:"
        );

        System.out.println(merged);
    }
}
