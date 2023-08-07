#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
};

int utils(TreeNode *root, map<TreeNode *, int>& dp);

int sumOfGrandChildren(TreeNode *root, map<TreeNode *, int>& dp){
    int sum = 0;
    if(root->left)  sum += utils(root->left->left, dp) + utils(root->left->right, dp);
    if(root->right) sum += utils(root->right->left, dp) + utils(root->right->right, dp);
    return sum;
}

int utils(TreeNode *root, map<TreeNode *, int>& dp){
    if(root == NULL)    return 0;
    if(dp.find(root) != dp.end())   return dp[root];
    // take node
    int take = root->val + sumOfGrandChildren(root, dp);
    //not take
    int not_take = utils(root->left, dp) + utils(root->right, dp);
    return dp[root] = max(take, not_take);
}

