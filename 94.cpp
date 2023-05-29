#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void utils(TreeNode *root, vector<int> &to_return)
{
	if (!root)
		return;
	utils(root->left, to_return);
	to_return.push_back(root->val);
	utils(root->right, to_return);
}

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> to_return;
	utils(root, to_return);
	return to_return;
}

int main()
{
	TreeNode *home = new TreeNode(1);
	home->right = new TreeNode(2);
	home->right->left = new TreeNode(3);
	vector<int> result = inorderTraversal(home);
	for (auto itt : result)
	{
		cout << itt << " ";
	}
	cout << endl;
}