#include <iostream>
#include <vector>
#define COUNT 10

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void utils(TreeNode *root, int& sum, bool even_parent, bool even_grand_parent){
    if(even_grand_parent) sum += root->val;
    if(!root->left && !root->right) return;
    bool is_even = false;
    if(root->val % 2 == 0)  is_even = true;
    if(root->left)  utils(root->left, sum, is_even, even_parent);
    if(root->right) utils(root->right, sum, is_even, even_parent);
}

int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;
    utils(root, sum, false, false);
    return sum;
}

void addNode(TreeNode *root, int val, bool right){
    if(right){
        root->right = new TreeNode(val);
    }else{
        root->left = new TreeNode(val);
    }
}

int main(){
    TreeNode *root = new TreeNode(6);
    addNode(root, 7, false);
    addNode(root, 8, true);
    addNode(root->left, 2, false);
    addNode(root->left, 7, true);
    addNode(root->right, 1, false);
    addNode(root->right, 3, true);
    addNode(root->left->left, 9, false);
    addNode(root->left->right, 1, false);
    addNode(root->left->right, 4, true);
    addNode(root->right->right, 5, true);
    cout << sumEvenGrandparent(root) << endl;
}