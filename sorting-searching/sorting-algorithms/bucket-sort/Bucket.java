import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;

public class Bucket {
    static void bucketSort(float[] arr) {
        int n = arr.length;

        ArrayList<Float>[] buckets = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (float num : arr) {
            int index = Math.min(n - 1, (int)(num * n));
            buckets[index].add(num);
        }

        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        int index = 0;
        for (int i = 0; i < n; i++) {
            for (float num : buckets[i]) {
                arr[index++] = num;
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};
        bucketSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}