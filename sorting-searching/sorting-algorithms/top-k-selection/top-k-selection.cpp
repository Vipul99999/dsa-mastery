
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> topKLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } 
        else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(result.rbegin(), result.rend());

    return result;
}

int main() {
    vector<int> arr = {12, 5, 7, 19, 3, 25, 8};
    int k = 3;

    vector<int> result = topKLargest(arr, k);

    cout << "Top " << k << " largest elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
