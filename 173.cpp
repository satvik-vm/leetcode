#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(vector<TreeNode *> &vec, TreeNode *root)
{
	if (!root)
		return;
	inorderTraversal(vec, root->left);
	vec.push_back(root);
	inorderTraversal(vec, root->right);
}
class BSTIterator
{
private:
	vector<TreeNode *> inOrderVec;
	int pt = 0;

public:
	BSTIterator(TreeNode *root)
	{
		inorderTraversal(inOrderVec, root);
	}

	int next()
	{
		pt++;
		cout << inOrderVec.size() << " " << pt << endl;
		return inOrderVec[pt - 1]->val;
	}

	bool hasNext()
	{
		return pt < inOrderVec.size();
	}
};