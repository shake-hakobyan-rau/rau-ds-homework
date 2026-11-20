#include <iostream>
#include <queue>

struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
  
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
 void levelOrder(TreeNode* root){
     if(root == nullptr) return;
     
     std::queue<TreeNode*> q;
     q.push(root);
     
     while(!q.empty()){
         TreeNode* cur = q.front();
         q.pop();
         std::cout << cur->value << " ";
         
         if(cur->left) q.push(cur->left);
         if(cur->right) q.push(cur->right);
     }
     std::cout << std::endl;
 }

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    levelOrder(root);

    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
