#include <iostream>
#include <algorithm>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
	if (root == nullptr) return;

	std::swap(root->left, root->right);

	mirrorTree(root->left);
	mirrorTree(root->right);
}

void printTree(TreeNode* root) {
	if (root == nullptr) return;

	std::cout << root->value << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);

	std::cout << "До: ";
	printTree(root);
	std::cout << std::endl;

	mirrorTree(root);

	std::cout << "После: ";
	printTree(root);
	std::cout << std::endl;

	delete root->left->left;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}
