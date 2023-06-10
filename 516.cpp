#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestPalindromeSubseq_1(string s){
	int n = s.length();
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> new_dp(n, 0);
        new_dp[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                new_dp[j] = 2 + dp[j - 1];
            }
            else
            {
                new_dp[j] = max(dp[j], new_dp[j - 1]);
            }
        }
        dp = new_dp;
    }
    return dp[n - 1];
}

int longestPalindromeSubseq(string s){
	string s2 = s;
	reverse(s2.begin(), s2.end());
	// return utils(s, s2, 0, 0, s.size());
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
	int size = s.size();
	dp[size][size] = 0;
	for(int i = 0; i < size; i++)	dp[i][size] = 0;
	for(int i = 0; i < size; i++)	dp[size][i] = 0;

	for(int i = size - 1; i >= 0; i--){
		for(int j = size - 1; j >= 0; j--){
			// int take = 0;
			if(s[i] == s2[j])	dp[i][j] = 1 + dp[i + 1][j + 1];
			else	dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	return dp[0][0];
}

int main()
{
    string s = "cbbd";
    cout << longestPalindromeSubseq(s) << endl;
}