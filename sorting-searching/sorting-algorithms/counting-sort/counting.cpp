#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);

    for (int x : arr) count[x]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) {
            arr[index++] = i;
        }
    }
}

int main() {
    vector<int> arr = {4,2,2,8,3,3,1};
    countingSort(arr);

    for(int x : arr) cout << x << " ";
}