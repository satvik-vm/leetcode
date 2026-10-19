#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left, *right;
};

class Solution{
public:
    vector<int> topView(TreeNode *root){
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        map<int, int> mp;
        while(!q.empty()){
            auto [node, vert] = q.front();
            q.pop();
            if(mp.find(vert) == mp.end())    mp[vert] = node->data;
            if(node->left)  q.push({node->left, vert - 1});
            if(node->right) q.push({node->right, vert + 1});
        }
        vector<int> ans;
        for(auto [key, val]: mp){
            ans.push_back(val);
        }
        return ans;
    }
};