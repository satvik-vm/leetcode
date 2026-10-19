#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int> tree;	// tree is one based
	int size;

	void createUtils(vector<int> nums, int left, int right, int index){
		if(left == right){
			tree[index] = nums[left];
			return;
		}

		int mid = (left + right) / 2;
		createUtils(nums, left, mid, 2 * index + 1);
		createUtils(nums, mid + 1, right, 2 * index + 2);

		tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
	}

	void updateUtils(int left, int right, int index, int val, int node){
		if(left > index || right < index)	return;

		if(left == right){
			tree[node] = val;
			return;
		}

		int mid = (left + right) / 2;

		updateUtils(left, mid, index, val, 2 * node + 1);
		updateUtils(mid + 1, right, index, val, 2 * node + 2);

		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

	int queryUtils(int left, int right, int node_left, int node_right, int node){
		if(right < node_left or left > node_right)	return 0;

		if(left <= node_left and node_right <= right)	return tree[node];

		int node_mid = (node_left + node_right) / 2;
		int left_val = queryUtils(left, right, node_left, node_mid, 2 * node + 1);
		int right_val = queryUtils(left, right, node_mid + 1, node_right, 2 * node + 2);

		return left_val + right_val;
	}


public:
	SegmentTree(int n){
		size = n;
		tree.resize(4 * n);
	}

	void create(vector<int> nums){
		createUtils(nums, 0, nums.size() - 1, 1);
	}

	void update(int index, int value){
		updateUtils(0, size - 1, index, value, 1);
	}

	int query(int left, int right){
		return queryUtils(left, right, 0, size - 1, 1);
	}

	void printTree(int node, int l, int r, string prefix = "", bool isLast = true)
	{
		cout << prefix << (isLast ? "└── " : "├── ")
			 << "[" << l << "," << r << "] = " << tree[node] << "\n";

		if (l == r) return;  // leaf

		int mid = (l + r) / 2;  // must match the mid used in your build
		string childPrefix = prefix + (isLast ? "    " : "│   ");

		printTree(2 * node + 1, l, mid, childPrefix, false);   // left
		printTree(2 * node + 2, mid + 1, r, childPrefix, true); // right
	}
};


int main(){
	vector<int> nums = {0, 1, 3, 5, -2, 3};
	SegmentTree *sg = new SegmentTree(nums.size());
	sg->create(nums);
	sg->printTree(0, 0, nums.size() - 1);
	cout << sg->query(1, 4) << endl << endl;
	sg->update(2, 100);
	sg->printTree(0, 0, nums.size() - 1);
	cout << sg->query(1, 4) << endl;
}