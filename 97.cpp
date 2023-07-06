#include <iostream>
#include <vector>

using namespace std;

int utils(vector<vector<vector<int>>> &dp, int index1, int index2, int index3, string s1, string s2, string s3)
{
	if (index1 == s1.size() && index2 == s2.size() && index3 == s3.size())
		return true;
	if (index3 == s3.size())
		return false;
	if (dp[index1][index2][index3] != -1)
		return dp[index1][index2][index3];
	int byS1 = false, byS2 = false;
	if (index1 < s1.size() && s1[index1] == s3[index3])
	{
		byS1 = utils(dp, index1 + 1, index2, index3 + 1, s1, s2, s3);
	}
	if (index2 < s2.size() && s2[index2] == s3[index3])
	{
		byS2 = utils(dp, index1, index2 + 1, index3 + 1, s1, s2, s3);
	}
	return dp[index1][index2][index3] = byS1 | byS2;
}

bool isInterleave(string s1, string s2, string s3)
{
	int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
	vector<vector<vector<int>>> dp(size1 + 1, vector<vector<int>>(size2 + 1, vector<int>(size3 + 1, -1)));
	return utils(dp, 0, 0, 0, s1, s2, s3);
}