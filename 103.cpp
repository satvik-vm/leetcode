#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int>> answer;
	if (root == NULL)
		return answer;
	queue<TreeNode *> q;
	bool rightToLeft = false;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		vector<int> row(size);
		for (int i = 0; i < size; i++)
		{
			TreeNode *curr = q.front();
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			int index = !rightToLeft ? i : size - 1 - i;
			row[index] = curr->val;
		}
		rightToLeft = !rightToLeft;
		answer.push_back(row);
	}
	return answer;
}