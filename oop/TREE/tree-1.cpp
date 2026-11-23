#include <iostream>

struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
  
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int countNode(TreeNode* root){
    if(root == nullptr) return 0;
    
    return 1 + countNode(root->left) + countNode(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    int count = countNode(root);
    std::cout << count << std::endl;
    
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
