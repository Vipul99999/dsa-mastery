// ============================================================
// Adaptive Hardware Resonance Sort (AHRS)
// A Data- and Architecture-Aware Self-Optimizing Sorting Framework
// ------------------------------------------------------------
// Core Idea:
//   Select the most appropriate sorting strategy based on:
//   - Data size
//   - Sortedness
//   - Duplicate ratio
//   - Value range
//   - Memory budget
//   - CPU core count
//   - Cache approximations
//   - Latency and stability requirements
// ------------------------------------------------------------
// Compile:
//   g++ -std=c++20 -O2 adaptive_hardware_resonance_sort.cpp -o ahrs
// Run:
//   ./ahrs
// ============================================================

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

// ============================================================
// Utility Functions
// ============================================================

template <typename T>
bool isSorted(const vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

template <typename T>
void printVector(const vector<T>& arr, size_t limit = 30) {
    cout << "[";
    for (size_t i = 0; i < arr.size() && i < limit; ++i) {
        if (i) cout << ", ";
        cout << arr[i];
    }
    if (arr.size() > limit) cout << ", ...";
    cout << "]\n";
}

// ============================================================
// Hardware Profile (approximate, portable)
// ============================================================

struct HardwareProfile {
    size_t l1CacheBytes = 32 * 1024;
    size_t l2CacheBytes = 512 * 1024;
    size_t l3CacheBytes = 8 * 1024 * 1024;
    size_t memoryBudgetBytes = 512ULL * 1024 * 1024;
    unsigned int cpuCores = 1;
};

HardwareProfile detectHardware() {
    HardwareProfile hw;
    hw.cpuCores = thread::hardware_concurrency();
    if (hw.cpuCores == 0) hw.cpuCores = 1;
    return hw;
}

// ============================================================
// Constraints
// ============================================================

struct SortConstraints {
    bool requireStable = false;
    bool lowLatency = false;
};

// ============================================================
// Data Profile
// ============================================================

struct DataProfile {
    size_t n = 0;
    double sortedness = 0.0;
    double duplicateRatio = 0.0;
    bool allNonNegative = false;
    long long valueRange = 0;
};

template <typename T>
DataProfile analyzeData(const vector<T>& arr) {
    DataProfile p;
    p.n = arr.size();

    if (arr.empty()) {
        p.sortedness = 1.0;
        return p;
    }

    size_t orderedPairs = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] <= arr[i]) ++orderedPairs;
    }

    p.sortedness = (arr.size() <= 1)
        ? 1.0
        : static_cast<double>(orderedPairs) /
          static_cast<double>(arr.size() - 1);

    unordered_map<T, int> freq;
    for (const auto& x : arr) {
        freq[x]++;
    }

    p.duplicateRatio = 1.0 - static_cast<double>(freq.size()) /
                                 static_cast<double>(arr.size());

    if constexpr (is_same_v<T, int>) {
        auto [minIt, maxIt] = minmax_element(arr.begin(), arr.end());
        p.allNonNegative = (*minIt >= 0);
        p.valueRange = static_cast<long long>(*maxIt) - *minIt;
    }

    return p;
}

// ============================================================
// Sorting Algorithms
// ============================================================

template <typename T>
void insertionSort(vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void threeWayQuickSortRec(vector<T>& arr, int l, int r) {
    if (l >= r) return;

    T pivot = arr[l];
    int lt = l;
    int i = l + 1;
    int gt = r;

    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[lt++], arr[i++]);
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[gt--]);
        } else {
            ++i;
        }
    }

    threeWayQuickSortRec(arr, l, lt - 1);
    threeWayQuickSortRec(arr, gt + 1, r);
}

template <typename T>
void threeWayQuickSort(vector<T>& arr) {
    if (!arr.empty()) {
        threeWayQuickSortRec(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    if (*min_element(arr.begin(), arr.end()) < 0) {
        sort(arr.begin(), arr.end());
        return;
    }

    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> output(arr.size());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int count[10] = {0}; 

        for (int x : arr) {
            count[(x / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        arr = output;
    }
}

// ============================================================
// Resonance Wave Sort (simplified implementation)
// ============================================================

struct Wave {
    size_t start;
    size_t end;
    int minValue;
}; 

vector<Wave> detectWaves(const vector<int>& arr) {
    vector<Wave> waves;
    if (arr.empty()) return waves;

    size_t start = 0;
    while (start < arr.size()) {
        size_t end = start;
        while (end + 1 < arr.size() && arr[end] <= arr[end + 1]) {
            ++end;
        }

        waves.push_back({start, end, arr[start]}); 
        start = end + 1;
    }

    return waves;
}

void resonanceWaveSort(vector<int>& arr) {
    auto waves = detectWaves(arr);
    if (waves.size() <= 1) return;

    stable_sort(waves.begin(), waves.end(),
        [](const Wave& a, const Wave& b) {
            if (a.minValue != b.minValue)
                return a.minValue < b.minValue;
            return a.start < b.start;
        }); 

    vector<int> temp;
    temp.reserve(arr.size());

    for (const auto& wave : waves) {
        for (size_t i = wave.start; i <= wave.end; ++i) {
            temp.push_back(arr[i]);
        }
    }

    stable_sort(temp.begin(), temp.end()); // correctness refinement
    arr = move(temp);
}

// ============================================================
// Strategy Enumeration
// ============================================================

enum class Strategy {
    INSERTION,
    THREE_WAY_QUICK,
    RADIX,
    RESONANCE_WAVE,
    STABLE_MERGE,
    LOW_LATENCY_STD_SORT
}; 

const char* strategyName(Strategy s) {
    switch (s) {
        case Strategy::INSERTION:
            return "Insertion Sort";
        case Strategy::THREE_WAY_QUICK:
            return "Three-Way Quick Sort";
        case Strategy::RADIX:
            return "Radix Sort";
        case Strategy::RESONANCE_WAVE:
            return "Resonance Wave Sort";
        case Strategy::STABLE_MERGE:
            return "Stable Merge Sort";
        case Strategy::LOW_LATENCY_STD_SORT:
            return "Low-Latency std::sort";
    }
    return "Unknown";
}

// ============================================================
// Strategy Selection Engine
// S = f(D, H, C)
// ============================================================

template <typename T>
Strategy chooseStrategy(const vector<T>& arr,
                        const HardwareProfile& hw,
                        const SortConstraints& constraints) {
    DataProfile p = analyzeData(arr);
    size_t estimatedBytes = p.n * sizeof(T);

    if (constraints.lowLatency) {
        return Strategy::LOW_LATENCY_STD_SORT;
    }

    if (constraints.requireStable) {
        if constexpr (is_same_v<T, int>) {
            if (p.sortedness > 0.90 || p.duplicateRatio > 0.20) {
                return Strategy::RESONANCE_WAVE;
            }
        }
        return Strategy::STABLE_MERGE;
    }

    if (p.n <= 64) {
        return Strategy::INSERTION;
    }

    if (p.sortedness > 0.98 && estimatedBytes <= hw.l2CacheBytes) {
        return Strategy::INSERTION;
    }

    if (p.duplicateRatio > 0.35) {
        return Strategy::THREE_WAY_QUICK;
    }

    if constexpr (is_same_v<T, int>) {
        if (p.allNonNegative &&
            p.valueRange < 50'000'000 &&
            p.n > 10'000 &&
            estimatedBytes <= hw.memoryBudgetBytes / 4) {
            return Strategy::RADIX;
        }

        if (p.sortedness > 0.75 || p.duplicateRatio > 0.10) {
            return Strategy::RESONANCE_WAVE;
        }
    }

    if (estimatedBytes > hw.memoryBudgetBytes / 2) {
        return Strategy::LOW_LATENCY_STD_SORT;
    }

    return Strategy::THREE_WAY_QUICK;
}

// ============================================================
// Adaptive Hardware Resonance Sort
// ============================================================

template <typename T>
void adaptiveHardwareResonanceSort(vector<T>& arr,
                                   const SortConstraints& constraints = {},
                                   bool verbose = true) {
    if (arr.size() <= 1) return;

    HardwareProfile hw = detectHardware(); 
    DataProfile p = analyzeData(arr);

    Strategy strategy = chooseStrategy(arr, hw, constraints);

    if (verbose) {
        cout << "========== Adaptive Hardware Resonance Sort ==========" << '\n';
        cout << "Elements:          " << p.n << '\n';
        cout << "Sortedness:        " << p.sortedness << '\n';
        cout << "Duplicate Ratio:   " << p.duplicateRatio << '\n';
        cout << "Value Range:       " << p.valueRange << '\n';
        cout << "CPU Cores:         " << hw.cpuCores << '\n';
        cout << "L3 Cache (bytes):  " << hw.l3CacheBytes << '\n';
        cout << "Memory Budget:     " << hw.memoryBudgetBytes << '\n';
        cout << "Selected Strategy: " << strategyName(strategy) << '\n';
        cout << '\n';
    }

    switch (strategy) {
        case Strategy::INSERTION:
            insertionSort(arr);
            break;

        case Strategy::THREE_WAY_QUICK:
            threeWayQuickSort(arr);
            break;

        case Strategy::RADIX:
            if constexpr (is_same_v<T, int>) {
                radixSort(arr);
            } else {
                sort(arr.begin(), arr.end());
            }
            break;

        case Strategy::RESONANCE_WAVE:
            if constexpr (is_same_v<T, int>) {
                resonanceWaveSort(arr);
            } else {
                stable_sort(arr.begin(), arr.end());
            }
            break;

        case Strategy::STABLE_MERGE:
            stable_sort(arr.begin(), arr.end());
            break;

        case Strategy::LOW_LATENCY_STD_SORT:
            sort(arr.begin(), arr.end());
            break;
    }
}

// ============================================================
// Benchmark Utility
// ============================================================

template <typename Func>
void benchmark(const string& name, Func sorter, vector<int> data) {
    auto start = chrono::high_resolution_clock::now(); 
    sorter(data);
    auto end = chrono::high_resolution_clock::now(); 

    auto us = chrono::duration_cast<chrono::microseconds>(
        end - start
    ).count(); 

    cout << name
         << " -> "
         << us
         << " us | Sorted: "
         << (isSorted(data) ? "YES" : "NO")
         << '\n';
}

// ============================================================
// Dataset Generators
// ============================================================

vector<int> generateRandomData(size_t n,
                               int minVal = 0,
                               int maxVal = 1'000'000) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(minVal, maxVal);

    vector<int> data(n);
    for (auto& x : data) {
        x = dist(gen);
    }
    return data;
}

vector<int> generateNearlySortedData(size_t n) {
    vector<int> data(n);
    for (size_t i = 0; i < n; ++i) {
        data[i] = static_cast<int>(i);
    }

    if (n > 10) {
        swap(data[n / 2], data[n / 2 + 1]);
        swap(data[n / 4], data[n / 4 + 1]);
    }

    return data;
}

vector<int> generateDuplicateHeavyData(size_t n) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(0, 20);

    vector<int> data(n);
    for (auto& x : data) {
        x = dist(gen);
    }
    return data;
}

// ============================================================
// Main
// ============================================================

int main() {
    vector<int> data = {
        45, 12, 78, 34, 23, 89, 1,
        56, 90, 67, 12, 34, 12,
        5, 5, 5, 2, 2, 2, 9, 9
    };

    cout << "Original Data:\n";
    printVector(data);
    cout << '\n';

    SortConstraints constraints;
    constraints.requireStable = false;
    constraints.lowLatency = false;

    adaptiveHardwareResonanceSort(data, constraints, true);

    cout << "Sorted Data:\n";
    printVector(data);

    cout << "\nVerification: "
         << (isSorted(data) ? "SUCCESS" : "FAILED")
         << "\n\n";

    benchmark(
        "AHRS (Random)",
        [](vector<int>& v) {
            adaptiveHardwareResonanceSort(v, {}, false);
        },
        generateRandomData(100000)
    );

    benchmark(
        "AHRS (Nearly Sorted)",
        [](vector<int>& v) {
            adaptiveHardwareResonanceSort(v, {}, false);
        },
        generateNearlySortedData(100000)
    );

    benchmark(
        "AHRS (Duplicate Heavy)",
        [](vector<int>& v) {
            adaptiveHardwareResonanceSort(v, {}, false);
        },
        generateDuplicateHeavyData(100000)
    );

    return 0;
}
