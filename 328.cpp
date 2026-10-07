#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x) {}
	ListNode(int x, ListNode *next) : val(x) , next(next) {}
};

class Solution {
public:
    ListNode* getOdd(ListNode* head){
        ListNode *new_head = new ListNode(head->val);
        ListNode *curr = new_head;
        while(head->next && head->next->next){
            head = head->next->next;
            ListNode *temp = new ListNode(head->val);
            curr->next = temp;
            curr = curr->next;
        }
        return new_head;
    }

    ListNode* getEven(ListNode* head){
        ListNode *new_head = new ListNode(head->val);
        ListNode *curr = new_head;
        while(head->next && head->next->next){
            head = head->next->next;
            ListNode *temp = new ListNode(head->val);
            curr->next = temp;
            curr = curr->next;
        }
        return new_head;
    }

    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* new_head = getOdd(head);
        ListNode *new_head_even = getEven(head->next);
        ListNode *curr = new_head;
        while(curr->next)   curr = curr->next;
        curr->next = new_head_even;
        return new_head;
    }
};