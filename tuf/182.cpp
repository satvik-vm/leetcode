#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
public:
	void traverse(TreeNode* root, vector<vector<int>>& answer){
		if(!root)   return;
		answer[1].push_back(root->val);
		traverse(root->left, answer);
		answer[0].push_back(root->val);
		traverse(root->right, answer);
		answer[2].push_back(root->val);
	}
	vector<vector<int>> treeTraversal(TreeNode* root){
		//your code goes here
		vector<vector<int>> answer(3);  //in, pre, post
		traverse(root, answer);
		return answer;
	}
};