#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool helper(TreeNode *root, TreeNode *subRoot){
    if(!root && !subRoot)   return true;
    if((!root && subRoot) || (root && !subRoot) || (root->val != subRoot->val))    return false;

    return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
}

bool helper1(TreeNode *root, TreeNode *subRoot){
    if(!root)    return false;
    if((root->val == subRoot->val) && helper(root, subRoot)) return true;
    return helper1(root->left, subRoot) || helper1(root->right, subRoot);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!subRoot)    return true;

    return helper1(root, subRoot);
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(0);
    root->left->left = new TreeNode(1);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    bool ans = isSubtree(root, subRoot);
    cout << ans << endl;
}