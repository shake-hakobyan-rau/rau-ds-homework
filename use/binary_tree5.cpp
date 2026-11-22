#include <iostream>
#include <queue>

struct TreeNode{
int data;
TreeNode* left;
TreeNode* right;
explicit TreeNode (int n) : data(n), left(nullptr), right(nullptr){}
};
void levelOrder(TreeNode* root){
if(root == nullptr){
    return;
}
std::queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
TreeNode* current = q.front();
q.pop();
std::cout << current->data << " ";
if(current->left != 0){
    q.push(current->left);
}
if(current->right != 0){
    q.push(current->right);
}    
}
}
int main(){
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
levelOrder(root);
std::cout << std::endl;
return 0;    
}
