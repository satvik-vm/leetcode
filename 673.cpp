#include <iostream>
#include <vector>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
	vector<int> dp(nums.size(), 1);
	vector<int> cnt(nums.size(), 1);
	int max_len = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				cnt[i] = cnt[j];
			}
			else if (nums[i] > nums[j] && dp[j] + 1 == dp[i])
			{
				cnt[i] += cnt[j];
			}
		}
		max_len = max(max_len, dp[i]);
	}
	int answer = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (dp[i] == max_len)
			answer += cnt[i];
	}
	return answer;
}