#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* deleteKthNode(ListNode* &head, int k) {
		// Your code goes here
		if(k == 1)  return head->next;
		k -= 2;
		ListNode * temp_head = head;
		while(k){
			head = head->next;
			k--;
		}
		head->next = head->next->next;
		return temp_head;
	}
};
