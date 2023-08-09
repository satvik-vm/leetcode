#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode () : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *utils(vector<int> vec, int start, int end)
{
	// cout << start << " " << end << endl;
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	TreeNode *root = new TreeNode(vec[mid]);
	root->left = utils(vec, start, mid - 1);
	root->right = utils(vec, mid + 1, end);
	return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
	ListNode *curr = head;
	vector<int> vec;
	while (curr)
	{
		vec.push_back(curr->val);
		curr = curr->next;
	}
	return utils(vec, 0, vec.size() - 1);
}