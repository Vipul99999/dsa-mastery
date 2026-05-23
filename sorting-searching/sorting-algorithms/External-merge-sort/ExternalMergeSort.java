import java.io.*;
import java.util.*;

public class ExternalMergeSort {

    static final int CHUNK_SIZE = 4;

    static int createSortedRuns(String inputFile) throws Exception {
        Scanner scanner = new Scanner(new File(inputFile));

        List<Integer> data = new ArrayList<>();

        while (scanner.hasNextInt()) {
            data.add(scanner.nextInt());
        }

        scanner.close();

        int runIndex = 0;

        for (int i = 0; i < data.size(); i += CHUNK_SIZE) {
            List<Integer> chunk =
                data.subList(i, Math.min(i + CHUNK_SIZE, data.size()));

            List<Integer> sortedChunk = new ArrayList<>(chunk);

            Collections.sort(sortedChunk);

            PrintWriter writer =
                new PrintWriter("run" + runIndex + ".txt");

            for (int value : sortedChunk) {
                writer.print(value + " ");
            }

            writer.close();

            runIndex++;
        }

        return runIndex;
    }

    static void mergeRuns(int totalRuns, String outputFile)
        throws Exception {

        List<List<Integer>> runs = new ArrayList<>();

        for (int i = 0; i < totalRuns; i++) {
            Scanner scanner =
                new Scanner(new File("run" + i + ".txt"));

            List<Integer> run = new ArrayList<>();

            while (scanner.hasNextInt()) {
                run.add(scanner.nextInt());
            }

            scanner.close();

            runs.add(run);
        }

        PriorityQueue<Integer> minHeap =
            new PriorityQueue<>();

        List<Integer> merged = new ArrayList<>();

        for (List<Integer> run : runs) {
            minHeap.addAll(run);
        }

        while (!minHeap.isEmpty()) {
            merged.add(minHeap.poll());
        }

        PrintWriter output =
            new PrintWriter(outputFile);

        for (int value : merged) {
            output.print(value + " ");
        }

        output.close();
    }

    public static void main(String[] args)
        throws Exception {

        PrintWriter input =
            new PrintWriter("input.txt");

        input.print("8 3 7 4 9 2 6 1");

        input.close();

        int totalRuns =
            createSortedRuns("input.txt");

        mergeRuns(totalRuns, "sorted_output.txt");

        System.out.println(
            "External Merge Sort completed."
        );

        System.out.println(
            "Check sorted_output.txt"
        );
    }
}
