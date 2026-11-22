#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;
    
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodes(Node* root){
    if(root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    assert(countNodes(root) == 6);

    Node* single = new Node(10);
    assert(countNodes(single) == 1);

    assert(countNodes(nullptr) == 0);

    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
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