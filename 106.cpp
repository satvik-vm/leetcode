#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *utils(vector<int> &inorder, vector<int> &postorder, map<int, int> &mp, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd)
{
	if (postorderStart > postorderEnd || inorderStart > inorderEnd)
		return NULL;
	TreeNode *root = new TreeNode(postorder[postorderEnd]);

	int index = mp[root->val];
	int rem = index - inorderStart;

	root->left = utils(inorder, postorder, mp, inorderStart, index - 1, postorderStart, postorderStart + rem - 1);
	root->right = utils(inorder, postorder, mp, index + 1, inorderEnd, postorderStart + rem, postorderEnd - 1);
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
	int inorderSize = inorder.size(), postorderSize = postorder.size();
	if (inorderSize != postorderSize)
		return NULL;
	map<int, int> mp;
	for (int i = 0; i < inorderSize; i++)
	{
		mp[inorder[i]] = i;
	}
	return utils(inorder, postorder, mp, 0, inorderSize - 1, 0, postorderSize - 1);
}

int main(){
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	TreeNode *root = buildTree(inorder, postorder);
}