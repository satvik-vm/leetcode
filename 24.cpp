#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
	if(!head || !head->next)	return head;

	ListNode *curr = head, *next_node, *to_return = head->next, *prev_node = NULL;

	while(curr){
		if(curr->next)	next_node = curr->next;
		else next_node = NULL;
		if(prev_node && next_node)	prev_node->next = next_node;
		if(next_node && next_node->next){
			curr->next = next_node->next;
		}
		else{
			cout << curr->val << endl;	
			curr->next = NULL;
		}
		if(next_node)	next_node->next = curr;
		cout << curr->val << endl;	
		prev_node = curr;
		curr = curr->next;
	}

	return to_return;
}

void addNode(ListNode *head, int val){
	ListNode *next_node = new ListNode(val);
	ListNode *curr = head;
	while(curr->next){
		curr = curr->next;
	}
	curr->next = next_node;
}

int main()
{
	ListNode *head = new ListNode(1);
	addNode(head, 2);
	addNode(head, 3);
	addNode(head, 4);
	addNode(head, 5);
	addNode(head, 6);

	ListNode *answer = swapPairs(head);
	while(answer){
		cout << answer->val << " ";
		answer = answer->next;
	}
	// cout << answer->val << " ";
	cout << endl;
}
