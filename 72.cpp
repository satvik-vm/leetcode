#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b, int c){
	int __min = min(a, b);
	return min(__min, c);
}

int utils(string word1, string word2, int index1, int index2, vector<vector<int>>& dp){
	if(index1 < 0)	return index2 + 1;
	if(index2 < 0)	return index1 + 1;
	if(dp[index1][index2] != -1)	return dp[index1][index2];

	if(word1[index1] == word2[index2])	return utils(word1, word2, index1 - 1, index2 - 1, dp);
	int insert = utils(word1, word2, index1, index2 - 1, dp);
	int __delete = utils(word1, word2, index1 - 1, index2, dp);
	int replace = utils(word1, word2, index1 - 1, index2 - 1, dp);
	return dp[index1][index2] = 1 + min(insert, __delete, replace);
}

int minDistance(string word1, string word2) {
	vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    // return utils(word1, word2, word1.size() - 1, word2.size() - 1, dp);
	for(int i = 0; i < word1.size(); i++)	dp[i][0] = i + 1;
	for(int i = 0; i < word2.size(); i++)	dp[0][i] = i + 1;

	for(int i = 1; i <= word1.size(); i++){
		for(int j = 1; j <= word2.size(); j++){
			if(word1[i] == word2[j])	dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	return dp[word1.size()][word2.size()];
}

int main(){
	string word1 = "horse";
	string word2 = "ros";
	cout << minDistance(word1, word2) << endl;
}