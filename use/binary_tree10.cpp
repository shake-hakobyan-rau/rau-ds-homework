#include <iostream>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void mirrorTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    std::swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
 }   
int main(){
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

mirrorTree(root);
std::cout << "root->right = "  << root->right->data << std::endl;
std::cout << "root->left = "  << root->left->data << std::endl;
std::cout << "root->right->right = "  << root->right->right->data << std::endl;
return 0;  
}
