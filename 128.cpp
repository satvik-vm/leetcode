#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	set<int> nums_set;
	for(int itt: nums)	nums_set.insert(itt);
	vector<int> __nums;
	for(int itt: nums_set)	__nums.push_back(itt);
	int result = 0, curr_result = 1;
	for(int i = 0;i < __nums.size() - 1; i++){
		// while(nums[i + 1] == nums[i])	i++;
		if(__nums[i + 1] == __nums[i] + 1){
			curr_result++;
		}
		else{
			if(curr_result > 1)	result = max(result, curr_result);
			curr_result = 1;
		}
	}
	if(curr_result > 1)	result = max(result, curr_result);
	return result;
}

int main(){
	vector<int> nums = {0,0};
	cout << longestConsecutive(nums) << endl;
}