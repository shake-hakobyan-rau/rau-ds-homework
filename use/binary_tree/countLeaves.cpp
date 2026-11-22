#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countLeaves(Node* root){
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    assert(countLeaves(root) == 3);
    assert(countLeaves(new Node(10)) == 1);
    assert(countLeaves(nullptr) == 0);

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