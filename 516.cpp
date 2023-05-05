#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestPalindromeSubseq(string s)
{
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

int main()
{
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
}