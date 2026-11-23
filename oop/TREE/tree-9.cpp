#include <iostream>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(TreeNode* root, int k) {
	if (root == nullptr) return 0;

	if (k == 1) return 1;

	return countNodesAtDepth(root->left, k - 1) +
	       countNodesAtDepth(root->right, k - 1);
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	int k = 3;
	int count = countNodesAtDepth(root, k);

	std::cout << "Count" << " = " << count << std::endl;

	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}
