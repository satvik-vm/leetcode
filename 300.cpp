#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int utils(vector<int> &nums, int prev, int i, vector<vector<int>> &dp)
{
	if (i >= nums.size())
		return 0;
	if (dp[i][prev + 1] != -1)
		return dp[i][prev + 1];
	int not_pick = utils(nums, prev, i + 1, dp);
	int pick = 0;
	if (prev == -1 || nums[i] > nums[prev])
	{
		pick = 1 + utils(nums, i, i + 1, dp);
	}
	return dp[i][prev + 1] = max(not_pick, pick);
}

int lengthOfLIS(vector<int> &nums)
{
	// vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    // return utils(nums, -1, 0, dp);
	// for(int index = nums.size() - 1; index >= 0; index--){
	// 	for(int prev = index - 1; prev >= -1; prev--){
	// 		int not_pick = dp[index + 1][prev + 1];
	// 		int pick = 0;
	// 		if(prev == -1 || nums[index] > nums[prev])	pick = 1 + dp[index + 1][index + 1];
	// 		dp[index][prev + 1] = max(pick, not_pick);
	// 	}
	// }
	// return dp[0][0];

	// vector<int> dp(n, 1);
	// for(int i = 1; i < n; i++){
	// 	for(int j = 0; j < i; j++){
	// 		if(nums[j] < nums[i])	dp[i] = max(dp[i], dp[j] + 1);
	// 	}
	// }

	// int max_num = INT_MIN;
	// for(int itt: dp){
	// 	max_num = max(itt, max_num);
	// }

	// return max_num;

	int n = nums.size();
	vector<int> result;
	result.push_back(nums[0]);

	for(int i = 1; i < n; i++){
		if(nums[i] > result[result.size() - 1]){
			result.push_back(nums[i]);
		}
		else{
			int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
			result[index] = nums[i];
		}
	}

	return result.size();
}

int main()
{
	vector<int> nums = {7,7,7,7,7,7,7};
	cout << lengthOfLIS(nums) << endl;
}