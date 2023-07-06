#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void utils(int n, int open, int close, vector<string> &answer, string &curr_answer)
{
	if (n == close)
	{
		answer.push_back(curr_answer);
		return;
	}
	if (open > n)
		return;
	if (open < n)
	{
		curr_answer.append("(");
		utils(n, open + 1, close, answer, curr_answer);
		curr_answer.pop_back();
	}
	if (open > 0 && close < open)
	{
		curr_answer.append(")");
		utils(n, open, close + 1, answer, curr_answer);
		curr_answer.pop_back();
	}
}
vector<string> generateParenthesis(int n)
{
	vector<string> answer;
	string curr_answer = "";
	int open = 0, close = 0;
	utils(n, open, close, answer, curr_answer);
	return answer;
}