#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
	int len1 = text1.size(), len2 = text2.size();
	for(int i = 0; i < len1; i++)	dp[i][len2] = 0;
	for(int i = 0; i < len2; i++)	dp[len1][i] = 0;
	dp[len1][len2] = 0;
	for(int i = len1 - 1; i >= 0; i--){
		for(int j = len2 - 1; j >= 0; j--){
			if(text1[i] == text2[j])	dp[i][j] = 1 + dp[i + 1][j + 1];
			else	dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return dp[0][0];
}

int main(){
	string text1 = "abcde";
	string text2 = "ace";
	cout << longestCommonSubsequence(text1, text2) << endl;
}