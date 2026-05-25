import java.util.*;

public class SpreadSort {

    static List<Integer> spreadSort(
        int[] arr,
        int bucketCount
    ) {
        int minValue = Arrays.stream(arr)
            .min()
            .getAsInt();

        int maxValue = Arrays.stream(arr)
            .max()
            .getAsInt();

        int range = maxValue - minValue + 1;

        List<List<Integer>> buckets =
            new ArrayList<>();

        for (int i = 0; i < bucketCount; i++) {
            buckets.add(new ArrayList<>());
        }

        for (int num : arr) {
            int bucketIndex =
                ((num - minValue)
                * bucketCount)
                / range;

            if (bucketIndex == bucketCount) {
                bucketIndex--;
            }

            buckets.get(bucketIndex).add(num);
        }

        List<Integer> result =
            new ArrayList<>();

        for (List<Integer> bucket : buckets) {
            Collections.sort(bucket);

            result.addAll(bucket);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {
            42, 7, 99, 15,
            63, 28, 84
        };

        System.out.println(
            "Original array:"
        );

        System.out.println(
            Arrays.toString(arr)
        );

        List<Integer> sorted =
            spreadSort(arr, 4);

        System.out.println(
            "\nSorted array:"
        );

        System.out.println(sorted);
    }
}
