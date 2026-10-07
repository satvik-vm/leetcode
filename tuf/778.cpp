#include <bits/stdc++.h>
using namespace std;

class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* &head) {
		ListNode *zeroHead = new ListNode;
		ListNode *oneHead = new ListNode;
		ListNode *twoHead = new ListNode;

		ListNode *zero = zeroHead;
		ListNode *one = oneHead;
		ListNode *two = twoHead;

		for(;head; head = head->next){
			if(head->data == 0){
				zero->next = head;
				zero = zero->next;
			}
			else if(head->data == 1){
				one->next = head;
				one = one->next;
			}
			else{
				two->next = head;
				two = two->next;
			}
		}
		two->next = NULL;
		if(oneHead->next){
			zero->next = oneHead->next;
			one->next = twoHead->next;
		}

		else{
			zero->next = twoHead->next;
		}

		return zeroHead->next;
	}
};