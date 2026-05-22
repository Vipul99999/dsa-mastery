import java.util.*;

public class Burstsort {

    static final int BURST_THRESHOLD = 3;

    static void burstsortRecursive(
        List<String> strings,
        int depth,
        List<String> result
    ) {
        if (strings.isEmpty()) {
            return;
        }

        if (strings.size() <= BURST_THRESHOLD) {
            List<String> temp = new ArrayList<>(strings);

            Collections.sort(temp);

            result.addAll(temp);

            return;
        }

        Map<Character, List<String>> buckets = new HashMap<>();

        for (String str : strings) {
            char key =
                depth < str.length()
                ? str.charAt(depth)
                : '\0';

            buckets.putIfAbsent(key, new ArrayList<>());

            buckets.get(key).add(str);
        }

        List<Character> keys = new ArrayList<>(buckets.keySet());

        Collections.sort(keys);

        for (char key : keys) {
            burstsortRecursive(
                buckets.get(key),
                depth + 1,
                result
            );
        }
    }

    static List<String> burstsort(List<String> strings) {
        List<String> result = new ArrayList<>();

        burstsortRecursive(strings, 0, result);

        return result;
    }

    public static void main(String[] args) {
        List<String> words = Arrays.asList(
            "apple",
            "apply",
            "ape",
            "april",
            "banana",
            "band",
            "ball"
        );

        System.out.println("Original strings:");
        System.out.println(words);

        List<String> sortedWords = burstsort(words);

        System.out.println("\nSorted strings:");
        System.out.println(sortedWords);
    }
}
