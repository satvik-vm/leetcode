#include <iostream>
#include <vector>

using namespace std;

void utils(vector<vector<int>> &graph, vector<vector<int>> &answer, vector<int> &curr_answer, int index)
{
	// cout << index << endl;
	int n = graph.size() - 1;
	if (index == n)
	{
		answer.push_back(curr_answer);
		return;
	}
	for (int node : graph[index])
	{
		curr_answer.push_back(node);
		utils(graph, answer, curr_answer, node);
		curr_answer.pop_back();
	}
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
	vector<vector<int>> answer;
	vector<int> curr_answer = {0};
	utils(graph, answer, curr_answer, 0);
	return answer;
}