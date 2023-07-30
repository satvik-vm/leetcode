#include <iostream>
#include <vector>

using namespace std;

bool isPresent(string str, vector<string> &wordDict)
{
	for (string s : wordDict)
	{
		if (s == str)
			return true;
	}
	return false;
}
void utils(string s, int index, string &curr_answer, vector<string> &answer, vector<string> &wordDict)
{
	if (index == s.size())
	{
		answer.push_back(curr_answer);
		return;
	}
	for (int i = index + 1; i <= s.size(); i++)
	{
		if (isPresent(s.substr(index, i - index), wordDict))
		{
			curr_answer += " ";
			curr_answer.append(s.substr(index, i - index));
			utils(s, i, curr_answer, answer, wordDict);
			curr_answer = curr_answer.substr(0, curr_answer.size() - i + index - 1);
		}
	}
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
	vector<string> answer;
	string curr_answer;
	utils(s, 0, curr_answer, answer, wordDict);
	for (int i = 0; i < answer.size(); i++)
	{
		answer[i] = answer[i].substr(1, answer[i].size() - 1);
	}
	return answer;
}