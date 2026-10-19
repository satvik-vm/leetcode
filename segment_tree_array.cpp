#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
	int size;
	vector<int> tree;
public:
	SegmentTree(int n){
		size = n;
		tree.resize(2 * size);
	}

	void build(vector<int> nums){
		for(int i = size; i < 2 * size; i++){
			tree[i] = nums[i - size];
		}

		for(int i = size - 1; i > 0; i--){
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}

	void update(int index, int val){
		index += size;
		tree[index] = val;

		for(int i = index; i > 0; i = i >> 1){
			tree[i>>1] = tree[i] + tree[i^1];
		}
	}

	int query(int left, int right){
		int answer = 0;
		left += size;
		right += size;
		for(; left < right; left << 1, right << 1){
			if(left&1){
				answer += tree[left];
				left++;
			}

			if(!(right&1)){	//even right
				answer += tree[right];
				right--;
			}
		}

		return answer;
	}
};

int main(){
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int n = nums.size();

	SegmentTree *sg = new SegmentTree(n);
	sg->build(nums);
	cout << sg->query(1, 2) << endl;
	sg->update(2, 1);
	cout << sg->query(1, 2) << endl;
}