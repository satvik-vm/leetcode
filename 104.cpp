#include <iostream>
#include <vector>

#define COUNT 10

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void utils(TreeNode* root, int height, int& max_height){
	// cout << root->val << endl;
	if(!root->left && !root->right){
		if(height > max_height)	max_height = height;
		// heights.push_back(height);
		return;
	}

	if(root->left)	utils(root->left, height+1, max_height);
	if(root->right)	utils(root->right, height+1, max_height);
}

int maxDepth(TreeNode* root) {
	// vector<int> heights;
	int height = 0, max_height = 0;
	utils(root, height, max_height);
	cout << endl;
	return max_height;
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
	TreeNode *root = new TreeNode(1);
	addNode(root, 2, true);
	addNode(root, 3, false);
	addNode(root->left, 4, true);
	addNode(root->left, 5, false);
	addNode(root->right, 6, true);
	addNode(root->right, 7, false);
	addNode(root->left->right, 10, true);

	print2D(root);

	cout << maxDepth(root) << endl;

}