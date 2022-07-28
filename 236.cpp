#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)    return NULL;
    if(root->val == p->val || root->val == q->val) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL)   return root;
    return (left != NULL) ? left : right;
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
    TreeNode* root = new TreeNode;
    root->val = 3;
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    TreeNode *node1 = newNode(5);
    TreeNode *node2 = newNode(4);
    time_start = chrono::high_resolution_clock::now();
    TreeNode* ans = lowestCommonAncestor(root, node1, node2);
    time_end = chrono::high_resolution_clock::now();
    cout << "The LCA of " << node1->val << " and " << node2->val << " is " << ans->val << endl;
    cout << "Done [" << time_diff.count() << " microseconds]" << endl << endl;
}