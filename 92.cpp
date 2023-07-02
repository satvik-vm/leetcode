#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseList(ListNode *head, ListNode *tail)
{
	ListNode *next = head;
	while (head != tail)
	{
		next = head->next;
		if (tail->next == NULL)
			tail->next = head;
		else
		{
			ListNode *temp = tail->next;
			tail->next = head;
			head->next = temp;
		}
		head = next;
	}
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
	if (!head->next || left == right)
		return head;
	ListNode *prevHead = new ListNode(-1, head);
	ListNode *curr = prevHead;

	ListNode *beforeLeft, *afterRight = NULL, *rightNode, *leftNode;

	int n = 0;
	while (curr != NULL)
	{
		if (n == left - 1)
			beforeLeft = curr;
		if (n == left)
			leftNode = curr;
		if (n == right)
			rightNode = curr;
		if (n == right + 1)
			afterRight = curr;
		curr = curr->next;
		n++;
	}
	beforeLeft->next = NULL;
	rightNode->next = NULL;
	reverseList(leftNode, rightNode);
	cout << leftNode->val << " " << rightNode->val << endl;

	beforeLeft->next = rightNode;
	leftNode->next = afterRight;

	cout << head->val << endl;

	return prevHead->next;
}

int main()
{
	ListNode *head = new ListNode(5);
	int left = 1;
	int right = 1;
	ListNode *answer = reverseBetween(head, left, right);
	while (answer)
	{
		cout << answer->val << " ";
		answer = answer->next;
	}
	cout << endl;
}