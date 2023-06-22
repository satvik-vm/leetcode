#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
	int val;
	vector<Node *> neighbors;
	Node()
	{
		val = 0;
		neighbors = vector<Node *>();
	}
	Node(int _val)
	{
		val = _val;
		neighbors = vector<Node *>();
	}
	Node(int _val, vector<Node *> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

Node *utils(map<Node *, Node *> &mp, Node *node)
{
	Node *clone = new Node(node->val);
	mp[node] = clone;
	vector<Node *> neigh;
	for (auto itt : node->neighbors)
	{
		if (mp.find(itt) != mp.end())
		{
			neigh.push_back(mp[itt]);
		}
		else
			neigh.push_back(utils(mp, itt));
	}
	clone->neighbors = neigh;
	return clone;
}

Node *cloneGraph(Node *node)
{
	map<Node *, Node *> mp;
	if (node == NULL)
		return NULL;
	if (node->neighbors.size() == 0) // if only one node present no neighbors
	{
		Node *clone = new Node(node->val);
		return clone;
	}
	return utils(mp, node);
}