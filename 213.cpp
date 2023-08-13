#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int> nums, vector<int> &dp, int index, int end)
{
	// cout << index << endl;
	if (index == end)
		return nums[index];
	if (index > end)
		return 0;
	if (dp[index] != -1)
		return dp[index];
	dp[index] = max(utils(nums, dp, index + 1, end), nums[index] + utils(nums, dp, index + 2, end));
	return dp[index];
}
int rob(vector<int> &nums)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	vector<int> dp(n + 1, -1);
	int zeroPick = utils(nums, dp, 0, n - 2);
	dp.clear();
	dp.resize(n + 1, -1);
	int zeroNotPick = utils(nums, dp, 1, n - 1);
	return max(zeroPick, zeroNotPick);
}