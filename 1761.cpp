#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int minTrioDegree(int n, vector<vector<int>> &edges)
{
	vector<set<int>> adj(n + 1);
	vector<int> edgeCount(n + 1, 0);
	int min_num = INT_MAX;
	for (vector<int> edge : edges)
	{
		adj[min(edge[0], edge[1])].insert(max(edge[0], edge[1]));
		edgeCount[edge[0]]++;
		edgeCount[edge[1]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j : adj[i])
		{
			for (int k : adj[j])
			{
				if (adj[i].count(k))
				{
					min_num = min(min_num, edgeCount[i] + edgeCount[j] + edgeCount[k] - 6);
				}
			}
		}
	}
	if (min_num == INT_MAX)
		return -1;
	return min_num;
}