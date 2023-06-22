#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool utils(vector<vector<int>> &edges, int n, int start)
{
	vector<bool> visited(n, false);
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < edges[curr].size(); i++)
		{
			if (visited[edges[curr][i]] && edges[curr][i] == start)
			{
				return true;
			}
			else
			{
				visited[edges[curr][i]] = true;
				q.push(edges[curr][i]);
			}
		}
	}
	return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
	vector<vector<int>> adj(numCourses);
	for (int i = 0; i < prerequisites.size(); i++)
	{
		adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}
	cout << "-----------ADJ-----------" << endl;
	for(int i = 0; i < adj.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < adj[i].size(); j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------END ADJ-----------" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		bool curr = utils(adj, numCourses, i);
		if (curr){
			cout << i << endl;
			return false;
		}
	}
	return true;
}

int main(){
	int numCourses = 5;
	vector<vector<int>> prerequisites = {{1,4},{2,4},{3,1},{3,2}};

	cout << canFinish(numCourses, prerequisites) << endl;
}