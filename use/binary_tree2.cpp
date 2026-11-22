#include <iostream>
#include <algorithm>

struct TreeNode{
int data;
TreeNode* left;
TreeNode* right;
explicit TreeNode (int val) : data(val), left(nullptr), right(nullptr){} 
};
int treeHeight(TreeNode* root){
if(root == nullptr){
    return 0;
}
int leftHeght = treeHeight(root->left);
int rightHeght = treeHeight(root->right);
return 1 + std::max(leftHeght, rightHeght);

}
int main(){
TreeNode* root = new TreeNode(1);    
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
int height = treeHeight(root);
std::cout << height << std::endl;   
return 0;
}
