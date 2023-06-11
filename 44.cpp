#include <iostream>
#include <vector>

using namespace std;

bool utils(string s, string p, int index1, int index2, vector<vector<int>>& dp){
	if(index1 == 0 && index2 == 0)	return true;
	if(index2 == 0 && index1 > 0)	return false;
	if(index1 == 0 && index2 > 0){
		for(int i = 1; i <= index2; i++){
			if(p[i-1] != '*')	return false;
		}
		return true;
	}
	if(dp[index1][index2] != -1)	return dp[index1][index2];

	if(s[index1 - 1] == p[index2 - 1] || p[index2 - 1] == '?')	return dp[index1][index2] = utils(s, p, index1 - 1, index2 - 1, dp);
	if(p[index2 - 1] == '*')	return dp[index1][index2] = utils(s, p, index1 - 1, index2, dp) | utils(s, p, index1, index2 - 1, dp);
	return dp[index1][index2] = false;
}

bool isMatch(string s, string p) {
	vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
	// return utils(s, p, s.size(), p.size(), dp);
	dp[0][0] = 1;
	for(int i = 1; i <= s.size(); i++)	dp[i][0] = 0;
	for(int i = 1; i <= p.size(); i++){
		bool flag = true;
		for(int j = 1; j <= i; j++){
			if(p[j - 1] != '*'){
				flag = false;
				break;
			}
		}
		dp[0][i] = flag;
	}

	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= p.size(); j++){
			if(s[i - 1] == p[j - 1] || p[j - 1] == '?')	dp[i][j] = dp[i - 1][j - 1];
			else if(p[j - 1] == '*')	dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
			else dp[i][j] = 0;
			// cout << "i: " << i << " j: " << j << " dp: " << dp[i][j] << endl;
		}
	}

	return dp[s.size()][p.size()];
}

int main(){
	string s = "aa";
	string p = "aa";
	if(isMatch(s, p))	cout << "True";
	else cout << "False";
	cout << endl;
}