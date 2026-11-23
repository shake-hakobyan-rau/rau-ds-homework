#include <iostream>

struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
  
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root){
    if(root == nullptr) return;
    
    std::cout << root->value << " ";
    
    preorder(root->left);
    preorder(root->right);
}
 
 void inorder(TreeNode* root){
     if(root == nullptr) return;
     
     inorder(root->left);
     std:: cout << root->value << " ";
     
     inorder(root->right);
 }
 
 void postorder(TreeNode* root){
     if(root == nullptr) return;
     
     postorder(root->left);
     postorder(root->right);
     
     std::cout << root->value << " ";
 }
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
   preorder(root);
   std::cout << std::endl;
   inorder(root);
   std::cout << std::endl;
   postorder(root);
   std::cout << std::endl;

    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
