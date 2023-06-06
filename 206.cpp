#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL, *curr = head, *next;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void addNode(ListNode* head, int val){
	ListNode* next_node = new ListNode(val);
	ListNode* curr = head;
	while(curr->next)	curr = curr->next;
	curr->next = next_node;
}

int main(){
	ListNode* head = new ListNode(1);
	addNode(head, 2);
	addNode(head, 3);
	addNode(head, 4);
	addNode(head, 5);

	ListNode* answer = reverseList(head);

	while(answer){
		cout << answer->val << " ";
		answer = answer->next;
	}
	cout << endl;
}