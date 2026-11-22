#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(Node* root){
    if (root == nullptr) return;

    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    mirrorTree(root);

    assert(root->left->data == 3);
    assert(root->right->data == 2);
    assert(root->right->right->data == 4);
    assert(root->right->left == nullptr);
    assert(root->left->left == nullptr);
    assert(root->left->right == nullptr);

    mirrorTree(nullptr);

    mirrorTree(root);
    assert(root->left->data == 2);
    assert(root->right->data == 3);
    assert(root->left->left->data == 4);

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