#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int recur(TreeNode* root, int& curr_max){
        if(!root)   return 0;
        int left = recur(root->left, curr_max);
        int right = recur(root->right, curr_max);

        if(left < 0)    left = 0;
        if(right < 0)   right = 0;

        curr_max = max(curr_max, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        int curr_ans = recur(root, ans);
        return ans;
    }
};