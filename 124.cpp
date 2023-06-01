#include <iostream>
#include <vector>
#include <climits>

#define COUNT 10

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int utils(TreeNode* root, int &max_value){
	if(!root)	return NULL;
	int left_max = max(0, utils(root->left, max_value));
	int right_max = max(0, utils(root->right, max_value));

	int max_partial = max(left_max, right_max) + root->val;

	int max_full = max(left_max + right_max + root->val, max_partial);

	max_value = max_full;

	return max_partial;
}

int maxPathSum(TreeNode* root) {
	int max_value = INT_MIN;
	utils(root, max_value);
	return max_value;
}

void addNode(TreeNode *parent, int data, bool left){
	TreeNode *curr = new TreeNode(data);
	if(left)	parent->left = curr;
	else	parent->right = curr;
}

void print2DUtil(TreeNode * root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(TreeNode * root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(){
	TreeNode *root = new TreeNode(2);
	addNode(root, -1, true);
	// addNode(root, 3, false);
	// addNode(root->right, 15, true);
	// addNode(root->right, 7, false);

	// print2D(root);

	cout << maxPathSum(root) << endl;
}