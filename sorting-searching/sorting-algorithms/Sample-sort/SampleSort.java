import java.util.*;

public class SampleSort {

    static List<Integer> sampleSort(
        int[] arr,
        int bucketCount
    ) {
        int n = arr.length;

        List<Integer> samples =
            new ArrayList<>();

        for (int i = 1; i < bucketCount; i++) {
            samples.add(
                arr[(i * n) / bucketCount]
            );
        }

        Collections.sort(samples);

        List<List<Integer>> buckets =
            new ArrayList<>();

        for (int i = 0; i < bucketCount; i++) {
            buckets.add(new ArrayList<>());
        }

        for (int num : arr) {
            int bucketIndex = 0;

            while (
                bucketIndex < samples.size()
                && num > samples.get(bucketIndex)
            ) {
                bucketIndex++;
            }

            buckets.get(bucketIndex).add(num);
        }

        for (List<Integer> bucket : buckets) {
            Collections.sort(bucket);
        }

        List<Integer> result =
            new ArrayList<>();

        for (List<Integer> bucket : buckets) {
            result.addAll(bucket);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {
            29, 14, 35, 8,
            42, 17, 23, 5, 31
        };

        System.out.println(
            "Original array:"
        );

        System.out.println(
            Arrays.toString(arr)
        );

        List<Integer> sorted =
            sampleSort(arr, 3);

        System.out.println(
            "\nSorted array:"
        );

        System.out.println(sorted);
    }
}
```
