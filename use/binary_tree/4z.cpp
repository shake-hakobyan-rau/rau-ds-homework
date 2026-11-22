#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(Node* root){
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);          
}

void inorder(Node* root){
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
   
    std::cout << "preorder:  "; preorder(root);   std::cout << "\n"; 
    std::cout << "inorder:   "; inorder(root);    std::cout << "\n";
    std::cout << "postorder: "; postorder(root);  std::cout << "\n";
   
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