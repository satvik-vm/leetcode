#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
	int start = 0, end = nums.size() - 1;
	int sum = 0;
	for (int itt : nums)
		sum += itt;
	if (sum < target)
		return 0;
	while (start <= end)
	{
		bool flag1 = false, flag2 = false;
		if (sum - nums[start] >= target)
		{
			cout << sum << " " << nums[start] << endl;
			sum -= nums[start];
			start++;
			flag1 = true;
		}
		if (sum - nums[end] >= target)
		{
			cout << sum << " " << nums[end] << endl;
			sum -= nums[end];
			end--;
			flag2 = true;
		}
		if (!flag1 || !flag2)
			break;
	}
	cout << "START: " << start << " END: " << end << endl;
	return end - start + 1;
}

int main()
{
	int target = 7;
	vector<int> nums = {2,3,1,2,4,3};
	cout << minSubArrayLen(target, nums) << endl;
}