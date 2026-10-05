#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteTail(ListNode* &head) {
		//your code goes here
		if(!head->next) return NULL;
		ListNode* temp_head = head, *prev;
		while(head->next){
			prev = head;
			head = head->next;
		}
		prev->next = NULL;
		return temp_head;
	}
};