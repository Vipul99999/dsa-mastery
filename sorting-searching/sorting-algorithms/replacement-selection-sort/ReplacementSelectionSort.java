import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class ReplacementSelectionSort {

    static List<Integer> mergeTwoSortedRuns(List<Integer> left, List<Integer> right) {
        List<Integer> result = new ArrayList<>();

        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left.get(i) <= right.get(j)) {
                result.add(left.get(i));
                i++;
            } else {
                result.add(right.get(j));
                j++;
            }
        }

        while (i < left.size()) {
            result.add(left.get(i));
            i++;
        }

        while (j < right.size()) {
            result.add(right.get(j));
            j++;
        }

        return result;
    }

    static List<Integer> mergeAllRuns(List<List<Integer>> runs) {
        if (runs.isEmpty()) {
            return new ArrayList<>();
        }

        List<Integer> result = runs.get(0);

        for (int i = 1; i < runs.size(); i++) {
            result = mergeTwoSortedRuns(result, runs.get(i));
        }

        return result;
    }

    static List<List<Integer>> generateRuns(int[] inputArray, int memorySize) {
        List<List<Integer>> runs = new ArrayList<>();
        PriorityQueue<Integer> currentHeap = new PriorityQueue<>();
        List<Integer> frozen = new ArrayList<>();

        int index = 0;

        while (index < inputArray.length && currentHeap.size() < memorySize) {
            currentHeap.add(inputArray[index]);
            index++;
        }

        List<Integer> currentRun = new ArrayList<>();
        int lastOutput = Integer.MIN_VALUE;

        while (!currentHeap.isEmpty()) {
            int smallest = currentHeap.poll();

            currentRun.add(smallest);
            lastOutput = smallest;

            if (index < inputArray.length) {
                int nextValue = inputArray[index];
                index++;

                if (nextValue >= lastOutput) {
                    currentHeap.add(nextValue);
                } else {
                    frozen.add(nextValue);
                }
            }

            if (currentHeap.isEmpty()) {
                runs.add(currentRun);
                currentRun = new ArrayList<>();

                for (int value : frozen) {
                    currentHeap.add(value);
                }

                frozen.clear();
                lastOutput = Integer.MIN_VALUE;
            }
        }

        return runs;
    }

    static List<Integer> replacementSelectionSort(int[] inputArray, int memorySize) {
        List<List<Integer>> runs = generateRuns(inputArray, memorySize);
        return mergeAllRuns(runs);
    }

    public static void main(String[] args) {
        int[] arr = {6, 2, 8, 3, 9, 1, 7, 4, 5};
        int memorySize = 3;

        List<List<Integer>> runs = generateRuns(arr, memorySize);

        System.out.println("Generated Runs:");
        for (int i = 0; i < runs.size(); i++) {
            System.out.println("Run " + (i + 1) + ": " + runs.get(i));
        }

        List<Integer> sortedArray = mergeAllRuns(runs);

        System.out.println("Final Sorted Output: " + sortedArray);
    }
}
