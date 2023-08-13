#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int utils(int num, vector<int> &dp)
{
	if (num == 0)
		return 0;
	if (num < 0)
		return 1e8;
	if (dp[num] != -1)
		return dp[num];
	int min_num = INT_MAX;
	for (int i = 0; i * i < num; i++)
	{
		min_num = min(min_num, utils(num - (i + 1) * (i + 1), dp));
	}
	return dp[num] = 1 + min_num;
}
int numSquares(int n)
{
	vector<int> dp(n + 1, -1);
	return utils(n, dp);
}