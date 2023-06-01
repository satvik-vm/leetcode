#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <set>

#define COUNT 10

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(0), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
	vector<vector<int>> result;
	map<int, map<int, multiset<int>>> map;
	queue<pair<TreeNode *, pair<int, int>>> queue;
	queue.push({root, {0, 0}});
	while(!queue.empty()){
		TreeNode *curr = queue.front().first;
		int ht = queue.front().second.first;
		int level = queue.front().second.second;
		queue.pop();
		map[ht][level].insert(curr->val);
		if(curr->left)	queue.push({curr->left, {ht - 1, level + 1}});
		if(curr->right)	queue.push({curr->right, {ht + 1, level + 1}});
	}

	for(auto itt1: map){
		vector<int> curr_result;
		for(auto itt2: itt1.second){
			curr_result.insert(curr_result.end(), itt2.second.begin(), itt2.second.end());
		}
		result.push_back(curr_result);
	}

	return result;
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

	print2D(root);

	vector<vector<int>> result = verticalTraversal(root);

	for(auto itt1: result){
		for(auto itt2: itt1){
		cout << itt2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}