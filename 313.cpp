#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int nthSuperUglyNumber(int n, vector<int> &primes)
{
	sort(primes.begin(), primes.end());
	int size = primes.size();
	vector<int> dp(n);
	dp[0] = 1;
	vector<int> indices(size, 0);
	for (int i = 0; i < n - 1; i++)
	{
		long long min_num = INT_MAX;
		for (int index = 0; index < size; index++)
		{
			min_num = min(min_num, (long long)dp[indices[index]] * primes[index]);
		}
		dp[i + 1] = (int)min_num;
		for (int index = 0; index < size; index++)
		{
			if (min_num == primes[index] * (long long)dp[indices[index]])
				indices[index]++;
		}
		// cout << dp[i + 1] << ", ";
	}
	return dp[n - 1];
}