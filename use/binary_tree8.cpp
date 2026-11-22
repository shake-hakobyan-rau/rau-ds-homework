#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool areIdentical(TreeNode* root1, TreeNode* root2){
if(root1 == nullptr && root2 == nullptr){
    return true;
}
if(root1 == nullptr || root2 == nullptr){
    return false;
}
return (root1->data == root2->data) && 
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right);
}
int main(){
TreeNode* tree1 = new TreeNode(1);
tree1->left = new TreeNode(2);
tree1->right = new TreeNode(3);

TreeNode* tree2 = new TreeNode(1);
tree2->left = new TreeNode(2);
tree2->right = new TreeNode(3);

bool identical = areIdentical(tree1, tree2);
std::cout << std::boolalpha << identical << std::endl;

return 0;    
}
