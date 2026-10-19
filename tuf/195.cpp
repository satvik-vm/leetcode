#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left, *right;
};

class Solution{
public:
	void recur(TreeNode* root, vector<int>& curr, vector<vector<int>>& ans){
		if(!root->left && !root->right){
			curr.push_back(root->data);
			ans.push_back(curr);
			curr.pop_back();
			return;
		}

		curr.push_back(root->data);
		if(root->left)  recur(root->left, curr, ans);
		if(root->right) recur(root->right, curr, ans);
		curr.pop_back();

	}
	vector<vector<int>> allRootToLeaf(TreeNode* root) {
		//your code goes here
		vector<vector<int>> ans;
		vector<int> curr;
		recur(root, curr, ans);
		return ans;
	}
};