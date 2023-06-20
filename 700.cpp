#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
	// cout << root->val << endl;
	if(root->val == val)	return root;
	if(root->val < val && root->right)	return searchBST(root->right, val);
	if(root->left)	return searchBST(root->left, val);
	return NULL;
}

void addNode(TreeNode *root, int val, bool left){
	TreeNode *next = new TreeNode(val);
	if(left)	root->left = next;
	else	root->right = next;
}

int main(){
	TreeNode *root = new TreeNode(4);
	addNode(root, 2, true);
	addNode(root, 7, false);
	addNode(root->left, 1, true);
	addNode(root->left, 3, false);

	int val = 2;

	TreeNode *answer = searchBST(root, val);
	cout << answer->val << endl;
}