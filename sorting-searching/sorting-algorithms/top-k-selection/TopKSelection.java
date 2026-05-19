import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.List;
import java.util.ArrayList;

public class TopKSelection {

    public static List<Integer> topKLargest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : arr) {
            if (minHeap.size() < k) {
                minHeap.add(num);
            }
            else if (num > minHeap.peek()) {
                minHeap.poll();
                minHeap.add(num);
            }
        }

        List<Integer> result = new ArrayList<>();

        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll());
        }

        result.sort(Collections.reverseOrder());

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {12, 5, 7, 19, 3, 25, 8};
        int k = 3;

        List<Integer> result = topKLargest(arr, k);

        System.out.println("Top " + k + " largest elements: " + result);
    }
}
