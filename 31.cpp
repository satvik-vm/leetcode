#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void nextPermutation(vector<int>& nums){
	int i;
	for(i = nums.size() - 2; i >= 0; i--){
		if(nums[i] < nums[i+1])	break;
	}
	if(i == -1){
		reverse(nums.begin(), nums.end());
		return;
	}
	int break_point = nums[i];
	int max_num = INT_MAX;
	int max_index;
	for(int j = i; j < nums.size(); j++){
		if(nums[j] > break_point && nums[j] < max_num){
			max_num = nums[j];
			max_index = j;
		}
	}
	swap(nums[i], nums[max_index]);
	sort(nums.begin()+i+1, nums.end());
}

int main(){
    vector<int> nums = {1,1,5};
    nextPermutation(nums);
    for(int itt: nums){
        cout << itt << " ";
    }
    cout << endl;
}