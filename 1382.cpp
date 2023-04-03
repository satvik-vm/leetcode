#include <iostream>
#include <vector>

#define COUNT 10

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode* root, vector<int> &result){
    if(!root)    return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

TreeNode* utils(vector<int> tree, int start, int end){
    if(start > end)    return NULL;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(tree[mid]);
    root->left = utils(tree, start, mid - 1);
    root->right = utils(tree, mid + 1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> result;
    inorderTraversal(root, result);
    TreeNode *new_root = utils(result, 0, result.size() - 1);
    return new_root;
}

void addNode(TreeNode *root, bool left, int val){
    if(left)    root->left = new TreeNode(val);
    else    root->right = new TreeNode(val);
}

void print2DUtil(TreeNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current TreeNode after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void printTree(TreeNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(){
    TreeNode *root = new TreeNode(2);
    addNode(root, false, 1);
    addNode(root, true, 3);
    // addNode(root->right, false, 3);
    // addNode(root->right->right, false, 4);

    TreeNode *new_root = balanceBST(root);

    printTree(root);
    cout << "\n" << "\n";
    printTree(new_root);
}

