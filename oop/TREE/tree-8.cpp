#include <iostream>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr && root2 == nullptr) return true;

	if (root1 == nullptr || root2 == nullptr) return false;

	if (root1->value != root2->value) return false;

	return areIdentical(root1->left, root2->left) &&
	       areIdentical(root1->right, root2->right);
}

int main() {
	TreeNode* tree1 = new TreeNode(1);
	tree1->left = new TreeNode(2);
	tree1->right = new TreeNode(3);

	TreeNode* tree2 = new TreeNode(1);
	tree2->left = new TreeNode(2);
	tree2->right = new TreeNode(3);

	TreeNode* tree3 = new TreeNode(1);
	tree3->left = new TreeNode(2);
	tree3->right = new TreeNode(99);

	std::cout << (areIdentical(tree1, tree2) ? "true" : "false") << std::endl;

	std::cout  << (areIdentical(tree1, tree3) ? "true" : "false") << std::endl;

	delete tree1->left;
	delete tree1->right;
	delete tree1;
	delete tree2->left;
	delete tree2->right;
	delete tree2;
	delete tree3->left;
	delete tree3->right;
	delete tree3;

	return 0;
}
