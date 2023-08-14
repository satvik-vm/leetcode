#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, int node, vector<int> &state)
{
	if (state[node] == 1)
		return false;
	if (state[node] == 2)
		return true;
	state[node] = 1;
	for (int itt : graph[node])
	{
		if (!dfs(graph, itt, state))
			return false;
	}
	state[node] = 2;
	return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
	vector<int> answer;
	int n = graph.size();
	vector<int> state(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (dfs(graph, i, state))
		{
			answer.push_back(i);
		}
	}
	return answer;
}