#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool recur(TreeNode *root){
        if(!root->left && !root->right) return true;
        int left_val = 0, right_val = 0;
        bool left_bool = true, right_bool = true;
        if(root->left){
            left_bool = recur(root->left);
            left_val = root->left->val;
        }
        if(root->right){
            right_bool = recur(root->right);
            right_val = root->right->val;
        }
        if(root->val != left_val + right_val)   return false;
        return left_bool & right_bool;
    }


    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
        return recur(root);
    }
};
