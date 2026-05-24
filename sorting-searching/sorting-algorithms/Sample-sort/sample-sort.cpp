#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sampleSort(vector<int>& arr, int bucketCount) {
    int n = arr.size();

    vector<int> samples;

    for (int i = 1; i < bucketCount; i++) {
        samples.push_back(arr[i * n / bucketCount]);
    }

    sort(samples.begin(), samples.end());

    vector<vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex = 0;

        while (
            bucketIndex < samples.size() &&
            num > samples[bucketIndex]
        ) {
            bucketIndex++;
        }

        buckets[bucketIndex].push_back(num);
    }

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    vector<int> result;

    for (auto& bucket : buckets) {
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
        29, 14, 35, 8,
        42, 17, 23, 5, 31
    };

    cout << "Original array:\n";
    printArray(arr);

    vector<int> sorted =
        sampleSort(arr, 3);

    cout << "\nSorted array:\n";
    printArray(sorted);

    return 0;
}
