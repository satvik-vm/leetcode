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

vector<TreeNode *> utils(int start, int end, vector<vector<vector<TreeNode *>>> &dp)
{
	if (start > end)
	{
		vector<TreeNode *> vec;
		vec.push_back(NULL);
		return vec;
	}
	if (!dp[start][end].empty())
		return dp[start][end];
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode *> left = utils(start, i - 1, dp);
		vector<TreeNode *> right = utils(i + 1, end, dp);
		for (TreeNode *l : left)
		{
			for (TreeNode *r : right)
			{
				dp[start][end].push_back(new TreeNode(i, l, r));
			}
		}
	}
	return dp[start][end];
}

vector<TreeNode *> generateTrees(int n)
{
	vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1));
	return utils(1, n, dp);
}

int main(){
	int n = 8;
	vector<TreeNode *> answer = generateTrees(n);
}