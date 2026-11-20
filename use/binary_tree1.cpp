#include <iostream>

struct TreeNode {
    int data;
    TreeNode* right;
    TreeNode* left;
    explicit TreeNode (int val) : data(val), right(nullptr), left(nullptr){}
};
int countNodes(TreeNode* root){
if(root == nullptr){
    return 0;
}
return 1 + countNodes(root->left) + countNodes(root->right);
}
int main(){
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

int count = countNodes(root);
std::cout << count << std::endl;    
}
