#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
	if (nums.size() == 1)
		return 0;
	int left = -1, right = -1, min_num = INT_MAX, max_num = INT_MIN;
	int n = nums.size();
	for (int i = 0; i < n - 1; i++)
	{
		if (nums[i] > nums[i + 1])
		{
			if (left == -1)
				left = i;
			right = i + 1;
			min_num = min(min_num, nums[i + 1]);
			max_num = max(max_num, nums[i]);
			while (left > 0 && nums[left - 1] > min_num)
			{
				left--;
			}
		}
		else if (max_num != INT_MIN && nums[i] < max_num)
		{
			right = i;
		}
	}
	if (max_num != INT_MIN && nums[n - 1] < max_num)
		right = n - 1;
	if (left == -1)
		return 0;
	cout << nums[left] << " " << nums[right] << endl;
	return right - left + 1;
}