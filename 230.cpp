#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void order(TreeNode *root, vector<int>& v){
    if(root == NULL)  return;
    order(root->left, v);
    v.push_back(root->val);
    order(root->right, v);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> order_vector;
    order(root, order_vector);
    return order_vector[k-1];
}


void addNode(TreeNode *root, int val, bool left){
    TreeNode *next = new TreeNode;
    next->val = val;
    next->left = NULL;
    next->right = NULL;
    if(left)    root->left = next;
    else    root->right = next;
}

int main(){
    TreeNode *root = new TreeNode;

    root->val = 5;
    root->left = NULL;
    root->right = NULL;

    addNode(root, 3, true);
    addNode(root, 6, false);
    addNode(root->left, 2, true);
    addNode(root->left, 4, false);
    addNode(root->left->left, 1, true);

    cout << kthSmallest(root, 3) << endl;
}

