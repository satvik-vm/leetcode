#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *root)
{
  if (root->left || root->right)
    return false;
  return true;
}

vector<int> utils(TreeNode *root, int &max_num)
{ // {min, max, sum}
  if (!root)
  {
    return {INT_MAX, INT_MIN, 0};
  }
  // vector<int> leftNode = {INT_MAX, INT_MIN, 0}, rightNode = {INT_MAX, INT_MIN, 0};
  vector<int> leftNode = utils(root->left, max_num);
  vector<int> rightNode = utils(root->right, max_num);
  if (root->val > leftNode[1] && root->val < rightNode[0])
  {
    max_num = max(max_num, root->val + leftNode[2] + rightNode[2]);
    return {min(leftNode[0], root->val), max(rightNode[1], root->val), leftNode[2] + rightNode[2] + root->val};
  }
  return {INT_MIN, INT_MAX, max(leftNode[2], rightNode[2])};
}

int maxSumBST(TreeNode *root)
{
  int max_num = 0;
  vector<int> rootNode = utils(root, max_num);
  return max_num;
}