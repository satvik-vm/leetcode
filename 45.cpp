#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int> &nums, int index, vector<int> &dp)
{
	if (index > nums.size() - 1)
	{
		return 1e7;
	}
	if (index == nums.size() - 1)
	{
		return dp[index] = 0;
	}
	if (dp[index] != -1)
		return dp[index];
	int curr, min_num = 1e7;
	for (int i = 0; i < nums[index]; i++)
	{
		curr = 1 + utils(nums, index + i + 1, dp);
		min_num = min(min_num, curr);
	}
	return dp[index] = min_num;
}

int jump(vector<int> &nums)
{
	if (nums.size() < 2)
		return 0;
	vector<int> dp(nums.size(), -1);
	return utils(nums, 0, dp);
}

int main(){
	vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
	cout << jump(nums) << endl;
}