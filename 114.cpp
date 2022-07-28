#include <iostream>
#include <chrono>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

TreeNode *helper(TreeNode *root){
    if(root == NULL)    return NULL;
    TreeNode *leftflat = helper(root->left);
    TreeNode *rightflat = helper(root->right);
    if(root->left != NULL){
        leftflat->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    TreeNode *last;
    if(rightflat)    last = rightflat;
    else if(leftflat)   last = leftflat;
    else last = root;
    return last;
}

void flatten(TreeNode* root) {
    helper(root);
}

TreeNode* newNode(int val){
    TreeNode* next = new TreeNode;
    next->val = val;
    next->left = NULL;
    next->right = NULL;
    return next;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
    time_start = chrono::high_resolution_clock::now();
    flatten(root);
    time_end = chrono::high_resolution_clock::now();
    while(root->right){
        cout << root->val << " ";
        root = root->right;
    }
    cout << root->val << endl;
    if(time_diff.count() < 1000000)cout << "Done [" << time_diff.count() << " microseconds]" << endl << endl;
    else cout << "Done [" << time_diff.count() / 1000000 << " seconds]" << endl << endl;
}