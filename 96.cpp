#include <iostream>
#include <vector>

using namespace std;

int utils(int start, int end, vector<vector<int>> &dp)
{
	if (start > end)
	{
		return 1;
	}
	if (dp[start][end] != -1)
		return dp[start][end];
	int count = 0;
	for (int i = start; i <= end; i++)
	{
		int left = utils(start, i - 1, dp);
		int right = utils(i + 1, end, dp);
		count += (left * right);
	}
	return dp[start][end] = count;
}

int numTrees(int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	return utils(1, n, dp);
}

int main(){
	int n = 19;
	cout << numTrees(n) << endl;
}