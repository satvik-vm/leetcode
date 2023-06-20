#include <iostream>
#include <vector>
#define COUNT 10


using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void print2DUtil(TreeNode* root, int space)
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
void print2D(TreeNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void addNode(TreeNode* root, int val){
	if(root->val > val){
		if(root->left){
			return addNode(root->left, val);
		}	
		else	root->left = new TreeNode(val);
	}	
	else if(root->val < val){
		if(root->right){
			return addNode(root->right, val);
		}	
		else	root->right = new TreeNode(val);
	}	
	return;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int middle = (nums.size() - 1) / 2;
	int start = 0, to_end = middle + 1;
	TreeNode *root = new TreeNode(nums[middle]);
	for(int i = 0; i < nums.size() / 2; i++){
		addNode(root, nums[start + i]);
		addNode(root, nums[to_end + i]);
	}
	if(nums.size() % 2 == 0)	addNode(root, nums[nums.size() - 1]);

	return root;
}

int main(){
	vector<int> nums = {1, 3};
	TreeNode *root = sortedArrayToBST(nums);
	print2D(root);
}