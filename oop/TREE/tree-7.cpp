#include <iostream>
#include <algorithm>
#include <climits>
struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
  
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
 int findMax(TreeNode* root){
     if(root == nullptr) return INT_MIN;
     
     int LeftMax = findMax(root->left);
     int RightMax = findMax(root->right);
     
     return std::max(root->value, std::max(LeftMax, RightMax));
 }
 
 int findMin(TreeNode* root){
     if(root == nullptr) return INT_MAX;
     
     int LeftMin = findMin(root->left);
     int RightMin = findMin(root->right);
     
     return std::min(root->value, std::min(LeftMin, RightMin));
 }

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    int maxVal = findMax(root);
    std::cout << maxVal << std::endl;
    int minVal = findMin(root);
    std::cout << minVal << std::endl;
    
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
