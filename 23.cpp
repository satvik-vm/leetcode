#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comp
{
public:
	bool operator()(ListNode *a, ListNode *b)
	{
		return (a->val > b->val);
	}
};

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		if (lists.size() == 0)
			return NULL;
		priority_queue<ListNode *, vector<ListNode *>, comp> pq;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i])
			{
				pq.push(lists[i]);
			}
		}

		ListNode *head = NULL;
		ListNode *curr = NULL;

		while (!pq.empty())
		{
			ListNode *top = pq.top();
			pq.pop();

			if (top->next)
			{
				pq.push(top->next);
			}

			if (!head)
			{
				head = top;
				curr = top;
			}

			else
			{
				curr->next = top;
				curr = curr->next;
			}
		}

		return head;
	}
};