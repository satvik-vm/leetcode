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
	vector<vector<int>> treeTraversal(TreeNode* root) {
		vector<int> pre, in, post;
		if (!root) return {in, pre, post};
		stack<pair<TreeNode*, int>> st;
		st.push({root, 1});
		while (!st.empty()) {
			auto [node, state] = st.top();
			st.pop();
			if (state == 1) {
				pre.push_back(node->val);
				st.push({node, 2});
				if (node->left) st.push({node->left, 1});
			} else if (state == 2) {
				in.push_back(node->val);
				st.push({node, 3});
				if (node->right) st.push({node->right, 1});
			} else {
				post.push_back(node->val);
			}
		}
		return {in, pre, post};
	}
};