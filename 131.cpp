#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isPalindrome(string str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}
	return true;
}

void util(string s, int index, vector<vector<string>> &result, vector<string> &curr_result)
{
	if (index == s.size())
	{
		result.push_back(curr_result);
		return;
	}
	for (int i = index; i < s.size(); i++)
	{
		if (isPalindrome(s, index, i))
		{
			curr_result.push_back(s.substr(index, i - index + 1));
			util(s, i + 1, result, curr_result);
			curr_result.pop_back();
		}
	}
}

vector<vector<string>> partition(string s)
{
	vector<vector<string>> result;
	vector<string> curr_result;
	util(s, 0, result, curr_result);
	return result;
}

int main()
{
	string s = "aab";
	vector<vector<string>> result = partition(s);
	for (auto itt1 : result)
	{
		for (auto itt2 : itt1)
		{
			cout << itt2 << " ";
		}
		cout << endl;
	}
}