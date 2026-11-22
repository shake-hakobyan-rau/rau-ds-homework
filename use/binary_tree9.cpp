#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
int countNodesAtDepth(TreeNode* root, int k, int cur){
if(root == nullptr){
    return 0;
}
if(cur == k){
    return 1;
}
return countNodesAtDepth(root->left, k, cur + 1) +
       countNodesAtDepth(root->right, k, cur + 1);
}
int main(){
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

int count = countNodesAtDepth(root, 3, 1);
std::cout << count << std::endl;
return 0;
}

