#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    inorder(root->left, result);
    result.push_back(root->value);
    inorder(root->right, result);
}

vector<int> treeSort(vector<int>& arr) {
    Node* root = nullptr;

    for (int value : arr) {
        root = insert(root, value);
    }

    vector<int> result;
    inorder(root, result);

    return result;
}

int main() {
    vector<int> arr = {5, 3, 7, 2, 4, 6, 8};

    vector<int> sorted = treeSort(arr);

    for (int value : sorted) {
        cout << value << " ";
    }

    return 0;
}
