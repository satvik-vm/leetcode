#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int val;
	Node *left, *right, *next;
};

Node *connect(Node *root)
{
	if (!root)
		return root;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size - 1; i++)
		{
			Node *curr = q.front();
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			Node *nextNode = q.front();
			curr->next = nextNode;
		}
		Node *curr = q.front();
		q.pop();
		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
		curr->next = NULL;
	}
	return root;
}