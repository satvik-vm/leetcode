#include <iostream>
#include <vector>

using namespace std;

int getFact(int n)
{
	int answer = 1;
	for (int i = 1; i <= n; i++)
		answer *= i;
	return answer;
}
string getPermutation(int n, int k)
{
	string answer = "";
	vector<int> nums;
	// int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		// fact = fact * i;
		nums.push_back(i);
	}
	int blockSize = getFact(n - 1);
	k--;
	while (true)
	{
		answer += to_string(nums[k / blockSize]);
		nums.erase(nums.begin() + k / blockSize);
		if (nums.size() == 0)
			return answer;
		k = k % blockSize;
		blockSize /= nums.size();
	}
	return answer;
}