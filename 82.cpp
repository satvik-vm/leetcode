#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *curr = head;
	int max_value = INT_MIN, min_value = INT_MAX;

	while (curr->next)
	{
		max_value = max(max_value, curr->val);
		min_value = min(min_value, curr->val);
		curr = curr->next;
	}

	max_value = max(max_value, curr->val);
	min_value = min(min_value, curr->val);

	curr = head;
	vector<int> vec(max_value - min_value + 1, 0);

	while (curr->next)
	{
		vec[curr->val - min_value]++;
		curr = curr->next;
	}
	vec[curr->val - min_value]++;

	ListNode *new_head = NULL;
	int first = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 1)
		{
			new_head = new ListNode(i + min_value);
			first = i;
			break;
		}
	}
	curr = new_head;

	for (int i = first + 1; i < vec.size(); i++)
	{
		if (vec[i] == 1)
		{
			ListNode *next_node = new ListNode(i + min_value);
			curr->next = next_node;
			curr = curr->next;
		}
	}

	return new_head;
}