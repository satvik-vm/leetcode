#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
	vector<vector<int>> adj(numCourses);
	for (int i = 0; i < prerequisites.size(); i++)
	{
		adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}

	vector<int> incount(numCourses, 0);

	for (auto itt1 : adj)
	{
		for (int itt2 : itt1)
			incount[itt2]++;
	}

	queue<int> q;
	for (int i = 0; i < numCourses; i++)
	{
		if (incount[i] == 0)
		{
			q.push(i);
		}
	}

	vector<int> answer;
	int count = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		answer.push_back(curr);
		for (int itt : adj[curr])
		{
			incount[itt]--;
			if (incount[itt] == 0)
			{
				q.push(itt);
			}
		}
		count++;
	}

	if (count != numCourses)
	{
		answer.clear();
	}
	return answer;
}