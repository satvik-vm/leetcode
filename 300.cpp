#include <iostream>
#include <vector>

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
	vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
    return utils(nums, -1, 0, dp);
}

int main()
{
	vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
	cout << lengthOfLIS(nums) << endl;
}