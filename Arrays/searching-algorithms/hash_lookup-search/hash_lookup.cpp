#include <iostream>
#include <vector>
#include <unordered_map>

class HashLookup {
    std::unordered_map<int, int> table;
public:
    // Preprocesses array in O(n) time. Stores first occurrence of each value.
    explicit HashLookup(const std::vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); ++i) {
            table.emplace(arr[i], static_cast<int>(i));
        }
    }

    // Average O(1) lookup time
    int search(int target) const {
        auto it = table.find(target);
        return (it != table.end()) ? it->second : -1;
    }

    size_t size() const { return table.size(); }
};

int main() {
    std::vector<int> arr = {42, 17, 89, 17, 5, 33, 91, 22};
    HashLookup lookup(arr);

    int target1 = 33;
    int target2 = 99;
    
    std::cout << "Index of " << target1 << ": " << lookup.search(target1) << "\n";
    std::cout << "Index of " << target2 << ": " << lookup.search(target2) << "\n";
    
    return 0;
}