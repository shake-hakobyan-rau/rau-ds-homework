#include <iostream>

struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
  
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

  int treeHeight(TreeNode* root){
      if (root == nullptr) return 0;
      
      int left = treeHeight(root-> left);
      int right = treeHeight(root->right);
      
      return 1 + (left > right ? left : right);
  }
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    int height = treeHeight(root);
    std::cout << height << std::endl;
    
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
