#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(Node* root){
    int result = root->data;
    if (root->left != nullptr) {
        int l = findMax(root->left);
        if (l > result) result = l;
    }
    if (root->right != nullptr) {
        int r = findMax(root->right);
        if (r > result) result = r;
    }
    return result;
}

int findMin(Node* root){
    int result = root->data;
    if (root->left != nullptr) {
        int l = findMin(root->left);
        if (l < result) result = l;
    }
    if (root->right != nullptr) {
        int r = findMin(root->right);
        if (r < result) result = r;
    }
    return result;
}

void test(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);

    assert(findMax(root) == 8);
    assert(findMin(root) == 1);

    assert(findMax(root->right) == 8);
    assert(findMin(root->right) == 8);

    root->left->left->left = new Node(100);
    assert(findMax(root) == 100);

    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}

int main(){
    test();
    std::cout << "all tests passed";
    return 0;
}