#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int BURST_THRESHOLD = 3;

void burstsortRecursive(
    const vector<string>& strings,
    int depth,
    vector<string>& result
) {
    if (strings.empty()) {
        return;
    }

    if (strings.size() <= BURST_THRESHOLD) {
        vector<string> temp = strings;
        sort(temp.begin(), temp.end());

        for (const string& s : temp) {
            result.push_back(s);
        }

        return;
    }

    unordered_map<char, vector<string>> buckets;

    for (const string& str : strings) {
        char key = depth < str.size() ? str[depth] : '\0';
        buckets[key].push_back(str);
    }

    vector<char> keys;

    for (const auto& pair : buckets) {
        keys.push_back(pair.first);
    }

    sort(keys.begin(), keys.end());

    for (char key : keys) {
        burstsortRecursive(buckets[key], depth + 1, result);
    }
}

vector<string> burstsort(vector<string>& strings) {
    vector<string> result;

    burstsortRecursive(strings, 0, result);

    return result;
}

int main() {
    vector<string> words = {
        "apple",
        "apply",
        "ape",
        "april",
        "banana",
        "band",
        "ball"
    };

    cout << "Original strings:\n";

    for (const string& word : words) {
        cout << word << endl;
    }

    vector<string> sortedWords = burstsort(words);

    cout << "\nSorted strings:\n";

    for (const string& word : sortedWords) {
        cout << word << endl;
    }

    return 0;
}

```
