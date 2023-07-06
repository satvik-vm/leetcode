#include <iostream>
#include <vector>

using namespace std;

void utils(int n, int k, int num, vector<vector<int>> &answer, vector<int> &curr_answer)
{
	if (k == 0)
	{
		answer.push_back(curr_answer);
		return;
	}
	if (num == n + 1)
		return;
	curr_answer.push_back(num);
	utils(n, k - 1, num + 1, answer, curr_answer);
	curr_answer.pop_back();
	utils(n, k, num + 1, answer, curr_answer);
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> answer;
	vector<int> curr_answer;
	utils(n, k, 1, answer, curr_answer);
	return answer;
}