#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(Node* root, int k){
    if (root == nullptr) return 0;
    if (k == 1) return 1;
    return countNodesAtDepth(root->left, k - 1) + countNodesAtDepth(root->right, k - 1);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    assert(countNodesAtDepth(root, 1) == 1);
    assert(countNodesAtDepth(root, 2) == 2);
    assert(countNodesAtDepth(root, 3) == 2);
    assert(countNodesAtDepth(root, 4) == 0);
    assert(countNodesAtDepth(nullptr, 1) == 0);

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

int main(){
    test();
    std::cout << "all tests passed";
    return 0;
}