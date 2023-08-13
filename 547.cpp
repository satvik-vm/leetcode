#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> graph, vector<bool> &isVisited, int index)
{
	isVisited[index] = true;
	for (int itt : graph[index])
	{
		if (!isVisited[itt])
			dfs(graph, isVisited, itt);
	}
}
int findCircleNum(vector<vector<int>> &isConnected)
{
	int n = isConnected.size();
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isConnected[i][j])
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	int answer = 0;
	vector<bool> isVisited(n, false);
	for (int i = 0; i < n; i++)
	{
		if (!isVisited[i])
		{
			dfs(graph, isVisited, i);
			answer += 1;
		}
	}
	return answer;
}