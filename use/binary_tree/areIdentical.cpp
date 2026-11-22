#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool areIdentical(Node* a, Node* b){
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->data == b->data
        && areIdentical(a->left, b->left)
        && areIdentical(a->right, b->right);
}

void test(){
    Node* tree1 = new Node(1);
    tree1->left = new Node(2);
    tree1->right = new Node(3);

    Node* tree2 = new Node(1);
    tree2->left = new Node(2);
    tree2->right = new Node(3);

    assert(areIdentical(tree1, tree2) == true);

    tree2->right->data = 4;
    assert(areIdentical(tree1, tree2) == false);
    tree2->right->data = 3;

    tree2->left->left = new Node(7);
    assert(areIdentical(tree1, tree2) == false);

    assert(areIdentical(nullptr, nullptr) == true);
    assert(areIdentical(tree1, nullptr) == false);

    delete tree2->left->left;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree1->left;
    delete tree1->right;
    delete tree1;
}

int main(){
    test();
    std::cout << "all tests passed";
    return 0;
}