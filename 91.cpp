#include <iostream>
#include <vector>

using namespace std;

bool isPresent(char s)
{
	int s_int = s - '0';
	if (s_int >= 0 && s_int <= 9)
		return true;
	return false;
}

bool isPresent(string s)
{
	if (s.size() == 1)
	{
		if (stoi(s) >= 1 && stoi(s) <= 9)
			return true;
	}
	if (s.size() == 2)
	{
		if (s[0] == '1' && isPresent(s[1]))
			return true;
		else if (s == "20" || s == "21" || s == "22" || s == "23" || s == "24" || s == "25" || s == "26")
			return true;
	}
	return false;
}

int utils(string s, int index, vector<int> &dp)
{
	if (index > s.size() - 1)
	{
		return dp[index] = 1;
	}
	if (dp[index] != -1)
		return dp[index];

	int one_char = 0, two_char = 0;
	if (isPresent(s.substr(index, 1)))
	{
		one_char = utils(s, index + 1, dp);
	}
	if (index < s.size() - 1 && isPresent(s.substr(index, 2)))
	{
		two_char = utils(s, index + 2, dp);
	}
	return dp[index] = one_char + two_char;
}

int numDecodings(string s)
{
	vector<int> dp(s.size() + 1, -1);
	utils(s, 0, dp);
	return dp[0];
}

int main(){
	string s = "111111111111111111111111111111111111111111111";
	cout << numDecodings(s) << endl;
}