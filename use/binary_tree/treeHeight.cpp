#include <iostream>
#include <cassert>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int treeHeight(Node* root){
    if (root == nullptr) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    assert(treeHeight(root) == 3);

    Node* single = new Node(10);
    assert(treeHeight(single) == 1);

    assert(treeHeight(nullptr) == 0);

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    delete single;
}

int main(){
    test();
    std::cout << "all tests passed";
    return 0;
}
