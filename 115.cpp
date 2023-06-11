#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int utils(string s, string t, int index1, int index2, vector<vector<int>>& dp){
	if(index2 < 0)	return 1;
	if(index1 < 0)	return 0;
	if(dp[index1][index2] != -1)	return dp[index1][index2];
	if(s[index1] == t[index2])	return dp[index1][index2] = utils(s, t, index1 - 1, index2 - 1, dp) + utils(s, t, index1 - 1, index2, dp);
	return dp[index1][index2] = utils(s, t, index1 - 1, index2, dp);
}

int numDistinct(string s, string t) {
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
	for(int i = 0; i <= s.size(); i++)	dp[i][0] = 1;
	for(int i = 1; i <= t.size(); i++)	dp[0][i] = 0;
	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
			if(s[i-1] == t[j-1])	dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else	dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[s.size()][t.size()];
}

int main(){
	string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s, t) << endl;
}

