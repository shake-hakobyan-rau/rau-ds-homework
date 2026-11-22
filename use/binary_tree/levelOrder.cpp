#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrder(Node* root){
    if (root == nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); 
        q.pop();
        std::cout << cur->data << " ";
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
    }
}

void test(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "levelOrder: "; 
    levelOrder(root);
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

int main(){
    test();
    return 0;
}