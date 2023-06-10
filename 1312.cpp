#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longestPalindrome(string s){
	string rev = s;
	reverse(rev.begin(), rev.end());

	int size = s.size();

	vector<vector<int>> dp(size + 1, vector<int>(size + 1, -1));

	dp[size][size] = 0;
	for(int i = 0; i < size; i++)	dp[i][size] = 0;
	for(int i = 0; i < size; i++)	dp[size][i] = 0;

	for(int i = size - 1; i >= 0; i--){
		for(int j = size - 1; j >= 0; j--){
			if(s[i] == rev[j])	dp[i][j] = 1 + dp[i + 1][j + 1];
			else dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	return dp[0][0];
}

int minInsertions(string s) {
    int size = s.size();
	return size - longestPalindrome(s);
}

int main(){
	string s = "leetcode";
	cout << minInsertions(s) << endl;
}