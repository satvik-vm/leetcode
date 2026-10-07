#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int data;
	ListNode *next;
	ListNode(int x) : data(x), next(NULL) {}
};

/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
public:
	ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
		//your code goes here
		if(head->data == X) return head->next;
		ListNode *temp_head = head;
		while(head->next && head->next->data != X){
			head = head->next;
		}
		if(head->next && head->next->data == X){
			head->next = head->next->next;
		}
		return temp_head;
	}
};