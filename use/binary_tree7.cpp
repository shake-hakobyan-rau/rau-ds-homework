#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
int findMax(TreeNode* root){
    if(root == nullptr){
        return INT_MIN;
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return std::max({root->data, leftMax, rightMax});
}
int findMin(TreeNode* root){
    if(root == nullptr){
        return INT_MAX;
    }
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return std::min({root->data, leftMin, rightMin});

}

int main(){
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(8);
root->left->left = new TreeNode(1);
int maxVal = findMax(root);
int minVal = findMin(root);
std::cout << maxVal << std::endl;
std::cout << minVal << std::endl;
return 0;
}
