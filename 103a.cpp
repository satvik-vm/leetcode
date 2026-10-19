#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recur(TreeNode* root, vector<vector<int>>& ans, int level, int side){  //side 0 is left
        if(!root)   return;
        if(ans.size() <= level){
            ans.push_back({});
        }
        if(side == 0){
            ans[level].push_back(root->val);
        }
        else{
            ans[level].insert(ans[level].begin(), root->val);
        }
        recur(root->left, ans, level + 1, side ^ 1);
        recur(root->right, ans, level + 1, side ^ 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recur(root, ans, 0, 0);
        return ans;
    }
};