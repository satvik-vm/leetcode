#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &color, int start)
{
	color[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int adj : graph[curr])
		{
			if (color[adj] == 0)
			{
				color[adj] = 3 - color[curr];
				q.push(adj);
			}
			else if (color[adj] == color[curr])
				return false;
		}
	}
	return true;
}
bool dfs(vector<vector<int>> graph, vector<int> &color, int start)
{
	// color[start] = 1;
	for (int adj : graph[start])
	{
		if (color[adj] == 0)
		{
			color[adj] = 3 - color[start];
			if (!dfs(graph, color, adj))
				return false;
		}
		else if (color[adj] == color[start])
		{
			return false;
		}
	}
	return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
	vector<int> color(graph.size(), 0);
	for (int i = 0; i < graph.size(); i++)
	{
		if (color[i] == 0)
		{
			color[i] = 1;
			bool answer = dfs(graph, color, i);
			if (!answer)
				return false;
			// if(answer)  return answer;
		}
	}
	return true;
}

int main(){
	vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
	cout << isBipartite(graph) << endl;
}