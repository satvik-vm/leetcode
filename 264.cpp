#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n)
{
	vector<int> dp(n);
	int index1 = 0, index2 = 0, index3 = 0;
	dp[0] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		dp[i + 1] = min({dp[index1] * 2, dp[index2] * 3, dp[index3] * 5});
		if (dp[i + 1] == dp[index1] * 2)
			index1++;
		if (dp[i + 1] == dp[index2] * 3)
			index2++;
		if (dp[i + 1] == dp[index3] * 5)
			index3++;
	}
	return dp[n - 1];
}