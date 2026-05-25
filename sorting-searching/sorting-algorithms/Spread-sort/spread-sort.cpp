#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spreadSort(vector<int>& arr, int bucketCount) {
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    int range = maxValue - minValue + 1;

    vector<vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex =
            (num - minValue) * bucketCount / range;

        if (bucketIndex == bucketCount) {
            bucketIndex--;
        }

        buckets[bucketIndex].push_back(num);
    }

    vector<int> result;

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());

        result.insert(
            result.end(),
            bucket.begin(),
            bucket.end()
        );
    }

    return result;
}

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {
        42, 7, 99, 15,
        63, 28, 84
    };

    cout << "Original array:\n";
    printArray(arr);

    vector<int> sorted =
        spreadSort(arr, 4);

    cout << "\nSorted array:\n";
    printArray(sorted);

    return 0;
}
