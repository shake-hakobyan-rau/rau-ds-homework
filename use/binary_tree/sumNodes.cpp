#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sumNodes(Node* root){
    if (root == nullptr) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    assert(sumNodes(root) == 10);
    assert(sumNodes(nullptr) == 0);
    assert(sumNodes(root->right) == 3);

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