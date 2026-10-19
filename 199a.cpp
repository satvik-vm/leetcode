#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        queue<pair<TreeNode *, int>> q;
        vector<int> ans;
        q.push({root, 0});

        while(!q.empty()){
            auto [curr, level] = q.front();
            q.pop();

            if(curr->left) q.push({curr->left, level + 1});
            if(curr->right) q.push({curr->right, level + 1});

            if(ans.size() <= level)  ans.push_back(curr->val);
            else ans[level] = curr->val;
        }

        return ans;
    }
};