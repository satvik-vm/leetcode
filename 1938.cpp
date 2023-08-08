#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
	TrieNode *children[2] = {NULL};
	int count = 0;

	bool containsKey(int bit)
	{
		if (children[bit] && children[bit]->count > 0)
			return true;
		return false;
	}

	void addNode(int bit, TrieNode *node)
	{
		children[bit] = node;
	}

	TrieNode *get(int bit)
	{
		return children[bit];
	}
};

class Trie
{
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode;
	}

	void insert(int n)
	{
		TrieNode *curr = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (n >> i) & 1;
			if (!curr->containsKey(bit))
			{
				curr->addNode(bit, new TrieNode());
			}
			curr = curr->get(bit);
			curr->count++;
		}
	}

	int maxXOR(int val)
	{
		TrieNode *curr = root;
		int answer = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (val >> i) & 1;
			if (curr && curr->containsKey(!bit))
			{
				answer = answer | (1 << i);
				curr = curr->get(!bit);
			}
			else if (curr)
			{
				curr = curr->get(bit);
			}
		}
		return answer;
	}

	void remove(int n)
	{
		TrieNode *curr = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (n >> i) & 1;
			if (curr)
			{
				curr = curr->get(bit);
				if (curr)
					curr->count--;
			}
		}
	}
};

class Solution
{
public:
	Trie tr;
	void dfs(vector<vector<int>> &graph, vector<vector<pair<int, int>>> &queries, int root, vector<int> &result)
	{
		tr.insert(root);
		for (int i = 0; i < queries[root].size(); i++)
		{
			int curr_result = tr.maxXOR(queries[root][i].second);
			result[queries[root][i].first] = curr_result;
		}
		for (int i = 0; i < graph[root].size(); i++)
		{
			dfs(graph, queries, graph[root][i], result);
		}
		tr.remove(root);
	}

	vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
	{
		vector<vector<int>> graph(parents.size());
		int root = -1;
		for (int i = 0; i < parents.size(); i++)
		{
			if (parents[i] == -1)
			{
				root = i;
			}
			else
			{
				graph[parents[i]].push_back(i);
			}
		}
		vector<vector<pair<int, int>>> reformatQueries(parents.size());
		for (int i = 0; i < queries.size(); i++)
		{
			reformatQueries[queries[i][0]].push_back({i, queries[i][1]});
		}
		vector<int> result(queries.size());
		dfs(graph, reformatQueries, root, result);
		return result;
	}
};