#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next = NULL;
        while(head){
            ListNode *new_node = new ListNode(head->val, next);
            next = new_node;
            head = head->next;
        }
        return next;
    }
};