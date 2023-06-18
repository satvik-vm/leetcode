#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void __isPalindrome(string s, vector<vector<int>> &isPalindrome)
{
	for (int i = 0; i < s.length(); i++)
	{
		isPalindrome[i][i] = 0;
		for (int j = i - 1, k = i + 1; j >= 0 && k < s.length(); j--, k++)
		{
			if (s[j] == s[k])
				isPalindrome[j][k] = 0;
			else
				break;
		}
		for (int j = i, k = i + 1; j >= 0 && k < s.length(); j--, k++)
		{
			if (s[j] == s[k])
				isPalindrome[j][k] = 0;
			else
				break;
		}
	}
}

int utils(string str, int start, vector<int> &dp, vector<vector<int>> isPalindrome)
{
	int end = str.size();
	if (start == end)
		return 0;
	if (dp[start] != -1)
		return dp[start];

	int min_num = INT_MAX;
	for (int index = start; index < end; index++)
	{
		if (isPalindrome[start][index] == 0)
		{
			int curr = 1 + utils(str, index + 1, dp, isPalindrome);
			min_num = min(min_num, curr);
		}
	}
	return dp[start] = min_num;
}

int minCut(string s)
{
	int n = s.size();
	vector<vector<int>> isPalindrome(n + 1, vector<int>(n + 1, -1));
	__isPalindrome(s, isPalindrome);
	vector<int> dp(n + 1, 0);
	dp[n] = 0;

	for (int start = n - 1; start >= 0; start--)
	{
		int min_num = INT_MAX;
		for (int index = start; index < n; index++)
		{
			if (isPalindrome[start][index] == 0)
			{
				int curr = 1 + dp[index + 1];
				min_num = min(min_num, curr);
			}
		}
		dp[start] = min_num;
	}
	return dp[0] - 1;
}

int main()
{
	string s = "ab";
	cout << minCut(s) << endl;
}