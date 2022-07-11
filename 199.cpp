#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum option{
    LEFT = 0,
    RIGHT = 1
};

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root)   return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int val;
        while(size--){
            TreeNode *curr = q.front();
            q.pop();
            val = curr->val;
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans.push_back(val);
    }
    return ans;
}

void formTree(TreeNode *root, int val, int option){
    TreeNode *next = new TreeNode;
    next->val = val;
    if(option == LEFT)  root->left = next;
    else if (option == RIGHT) root->right = next;
}

int main(){
    TreeNode *root = new TreeNode;
    root->val = 1;
    formTree(root, 2, RIGHT);
    // formTree(root, 3, RIGHT);
    // formTree(root->left, 5, RIGHT);
    // formTree(root->right, 4, RIGHT);
    vector<int> ans = rightSideView(root);
    for(int answer : ans)   cout << answer << " ";
    cout << endl;
}