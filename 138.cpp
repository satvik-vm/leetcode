#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

Node *copyRandomList(Node *head)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
	{
		Node *new_head = new Node(head->val);
		if (head->random != NULL)
			new_head->random = new_head;
		return new_head;
	}
	map<Node *, Node *> mp;
	Node *curr = head->next;
	Node *new_head = new Node(head->val);
	Node *new_curr = new_head;
	mp[head] = new_head;

	while (curr->next)
	{
		Node *next_node = new Node(curr->val);
		new_curr->next = next_node;
		mp[curr] = next_node;
		curr = curr->next;
		new_curr = new_curr->next;
	}
	Node *next_node = new Node(curr->val);
	new_curr->next = next_node;
	mp[curr] = next_node;

	new_curr = new_head;
	curr = head;

	while (curr->next)
	{
		new_curr->random = mp[curr->random];
		new_curr = new_curr->next;
		curr = curr->next;
	}
	new_curr->random = mp[curr->random];

	return new_head;
}