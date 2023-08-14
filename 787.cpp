#include <iostream>
#include <vector>
#include <queue>

#define INF 1e8

using namespace std;

vector<int> dijkstra(int n, vector<vector<vector<int>>> graph, int src, int k, int finalDest)
{
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, src, 0}); // 0: stops, 1: node, 2: dis
	vector<int> dist(n, INF);
	dist[src] = 0;
	while (!pq.empty())
	{
		int stops = pq.top()[0];
		int pt = pq.top()[1];
		int dis = pq.top()[2];
		pq.pop();
		for (vector<int> itt : graph[pt])
		{
			int dest = itt[0];
			int wt = itt[1];
			if (stops <= k && dist[dest] > dis + wt)
			{
				dist[dest] = dis + wt;
				pq.push({stops + 1, dest, dist[dest]});
			}
		}
	}
	return dist;
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
	vector<vector<vector<int>>> graph(n);
	for (vector<int> itt : flights)
	{
		graph[itt[0]].push_back({itt[1], itt[2]}); // 0: destinatiion, 1: wt
	}
	vector<int> dist = dijkstra(n, graph, src, k, dst);
	return dist[dst] >= INF ? -1 : dist[dst];
}