#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraysWithKDistinct(vector<int> &nums, int k)
{
	return atMostK(nums, k) - atMostK(nums, k - 1);
}

int atMostK(vector<int> &nums, int k)
{
	int start = 0;
	int end = 0;
	map<int, int> mp;
	int answer = 0;
	for (; end < nums.size(); end++)
	{
		if (mp[nums[end]] == 0)
		{
			k--;
		}
		mp[nums[end]]++;
		while (k < 0)
		{
			mp[nums[start]]--;
			if (mp[nums[start]] == 0)
			{
				k++;
			}
			start++;
		}
		answer += end - start + 1;
		// end++;
	}
	return answer;
}