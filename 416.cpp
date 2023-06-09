#include <iostream>
#include <vector>

using namespace std;

bool utils(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
	if(target == 0)	return true;
	if(index == nums.size() - 1)	return nums[index] == target;
	if(dp[index][target] != -1)	return dp[index][target];
	bool take = false;
	if(nums[index] < target){
		take = utils(nums, index + 1, target - nums[index], dp);
	} 
	bool dont_take = utils(nums, index + 1, target, dp);
	return dp[index][target] = take || dont_take;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
	for(auto itt: nums)	sum += itt;
	if(sum % 2 == 1)	return false;
	vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
	return utils(nums, 0, sum / 2, dp);
}

int main(){
	vector<int> nums = {1,2,3,5};
	// cout << canPartition(nums) << endl;
	if(canPartition(nums))	cout << "true";
	else cout << "false";
	cout << endl;
}