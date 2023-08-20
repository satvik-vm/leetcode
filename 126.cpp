#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int stringDiff(string s1, string s2)
{
	int answer = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
			answer++;
	}
	return answer;
}
void bfs(map<string, vector<string>> &graph, string start, string end, map<string, vector<string>> &parent)
{
	int n = graph.size();
	// vector<int> dist(n, INT_MAX);
	map<string, int> dist;
	for (auto itt : graph)
	{
		dist[itt.first] = INT_MAX;
	}
	cout << start << endl;
	dist[start] = 0;
	queue<string> q;
	q.push(start);
	parent[start] = {"#"};
	while (!q.empty())
	{
		string s = q.front();
		q.pop();
		for (string itt : graph[s])
		{
			if (dist[itt] > dist[s] + 1)
			{
				dist[itt] = dist[s] + 1;
				parent[itt].clear();
				parent[itt].push_back(s);
				q.push(itt);
			}
			else if (dist[itt] == dist[s] + 1)
			{
				parent[itt].push_back(s);
			}
		}
	}
}
void returnPath(map<string, vector<string>> &parent, string end, vector<vector<string>> &paths, vector<string> curr_path)
{
	if (end == "#")
	{
		paths.push_back(curr_path);
		return;
	}
	for (string itt : parent[end])
	{
		curr_path.push_back(itt);
		returnPath(parent, itt, paths, curr_path);
		curr_path.pop_back();
	}
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
	int n = wordList.size();
	map<string, vector<string>> graph;
	bool beginWordPresent = false;
	for (int i = 0; i < n; i++)
	{
		if (wordList[i] == beginWord)
			beginWordPresent = true;
		for (int j = i + 1; j < n; j++)
		{
			if (stringDiff(wordList[i], wordList[j]) == 1)
			{
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		}
	}
	if (!beginWordPresent)
	{
		for (int i = 0; i < n; i++)
		{
			if (stringDiff(beginWord, wordList[i]) == 1)
			{
				graph[beginWord].push_back(wordList[i]);
			}
		}
	}
	vector<string> curr_answer;
	vector<vector<string>> answer;
	map<string, vector<string>> parent;
	bfs(graph, beginWord, endWord, parent);
	returnPath(parent, endWord, answer, curr_answer);
	for (vector<string> &itt : answer)
	{
		itt.pop_back();
		reverse(itt.begin(), itt.end());
		itt.push_back(endWord);
	}
	return answer;
}