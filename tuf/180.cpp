#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left, *right;
};

class Solution{
public:
    void recur(TreeNode* root, map<int, pair<int, int>>& mp, int vert, int depth){
        if(!root)   return;
        if(mp.find(vert) == mp.end())   mp[vert] = {root->data, depth};
        else{
            if(mp[vert].second > depth) mp[vert] = {root->data, depth};
        }
        recur(root->left, mp, vert - 1, depth + 1);
        recur(root->right, mp, vert + 1, depth + 1);
    }

    vector<int> topView(TreeNode *root){
        //your code goes here
        map<int, pair<int, int>> mp;
        recur(root, mp, 0, 0);
        vector<int> ans;
        for(const auto [key, data]: mp){
            ans.push_back(data.first);
        }
        return ans;
    }
};