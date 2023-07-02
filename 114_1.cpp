#include <iostream>
#define COUNT 10

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode) {}
};

void print2DUtil(TreeNode *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current TreeNode after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->val << "\n";

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNode *root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

void addNode(TreeNode *root, int val)
{
	TreeNode *curr = root;
	while (curr->right)
	{
		curr = curr->right;
	}
	curr->right = new TreeNode(val);
}

void utils(TreeNode *root, TreeNode *to_add)
{
	if (!to_add)
		return;
	addNode(root, to_add->val);
	utils(root, to_add->left);
	utils(root, to_add->right);
}

void flatten(TreeNode *&root)
{
	TreeNode *dummy = new TreeNode(-1);
	utils(dummy, root);
	TreeNode *curr = root, *curr1 = dummy->right;
	while (curr1)
	{
		curr->val = curr1->val;
		curr->right = curr1->right;
		curr->left = NULL;
		curr1 = curr1->right;
		curr = curr->right;
	}
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);
	flatten(root);
	print2D(root);
}