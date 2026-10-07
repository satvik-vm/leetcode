#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
	ListNode(int x) : data(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : data(x), next(next) {}
};

class Solution {
public:
	ListNode* insertAtTail(ListNode* &head, int X) {
		//your code goes here
		if(head == NULL)    return new ListNode(X);
		ListNode *temp_head = head;
		while(head->next){
			head = head->next;
		}
		head->next = new ListNode(X);
		return temp_head;
	}
};