#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
	vector<int> mod;
	map<int, bool> mp;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		sum %= k;
		mod.push_back(sum);
		if (i > 0 && nums[i] == nums[i - 1] && nums[i] == 0)
			return true;
	}
	mp[0] = true;
	for (int i = 1; i < mod.size(); i++)
	{
		if (mp[mod[i]])
			return true;
		mp[mod[i - 1]] = true;
	}
	return false;
}