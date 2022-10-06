#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    queue<TreeNode *> queue;
    if(root == NULL) return answer;
    queue.push(root);
    while(!queue.empty()){
        vector<int> result;
        int size = queue.size();
        for(int i = 0; i < size; i++){
            TreeNode *curr = queue.front();
            queue.pop();
            result.push_back(curr->val);
            if(curr->left != NULL){
                queue.push(curr->left);
            }
            if(curr->right != NULL){
                queue.push(curr->right);
            }
        }
        answer.push_back(result);
    }
    return answer;
}

TreeNode *binaryTree(TreeNode *root, int n, bool left){
    TreeNode *next = new TreeNode;
    next->val = n;
    if(left)    root->left = next;
    else    root->right = next;
    return next;
}

int main(){
    TreeNode *root = new TreeNode;
    root->val = 3;
    root->left = binaryTree(root, 9, 1);
    root->right = binaryTree(root, 20, 0);
    root->right->left = binaryTree(root->right, 15, 1);
    root->right->right = binaryTree(root->right, 7, 0);
    vector<vector<int>> answer = levelOrder(root);
    cout << "[";
    for(auto itt1 : answer){
        cout << "[";
        for (auto itt2: itt1){
            cout << itt2 << ", ";
        }
        cout << "],";
    }
    cout << "]";
}

