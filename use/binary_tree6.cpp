#include <iostream>


struct TreeNode{
int data;
TreeNode* left;
TreeNode* right;
explicit TreeNode (int n) : data(n), left(nullptr), right(nullptr){}
};
int sumNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int main(){
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

int sum = sumNodes(root);
std::cout << sum << std::endl; 
return 0;    
}
