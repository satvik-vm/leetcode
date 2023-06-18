#include <iostream>
#include <vector>

using namespace std;

bool utils(string &s, vector<string> &wordDict, int index, vector<int> &dp)
{
	if (index == s.size())
		return true;
	if (dp[index] != -1)
		return dp[index];
	for (int i = 0; i < wordDict.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < wordDict[i].size(); j++)
		{
			if (index + j >= s.size() || s[index + j] != wordDict[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (utils(s, wordDict, index + wordDict[i].size(), dp))
				return dp[index] = true;
		}
	}

	return dp[index] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
	vector<int> dp(s.size() + 1, -1);
	return utils(s, wordDict, 0, dp);
}

int main(){
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	if(wordBreak(s, wordDict))	cout << "true";
	else cout << "false";
	cout << endl;
}