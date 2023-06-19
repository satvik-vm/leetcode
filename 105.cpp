#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* utils(vector<int> preorder, vector<int> inorder, map<int, int> map, int inorder_start, int inorder_end, int preorder_start, int preorder_end){
	if(inorder_start > inorder_end || preorder_start > preorder_end)	return NULL;

	TreeNode* root = new TreeNode(preorder[preorder_start]);

	int left_num = map[preorder[preorder_start]] - inorder_start;

	root->left = utils(preorder, inorder, map, inorder_start, map[preorder[preorder_start]] - 1, preorder_start + 1, preorder_start + left_num);

	root->right = utils(preorder, inorder, map, map[preorder[preorder_start]] + 1, inorder_end, preorder_start + left_num + 1, preorder_end);

	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	map<int, int> map;
	for(int i = 0; i < inorder.size(); i++){
		map[inorder[i]] = i;
	}

	TreeNode *root = utils(preorder, inorder, map, 0, inorder.size() - 1, 0, preorder.size() - 1);

	return root;
}

int main(){
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
}