#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head){
        ListNode *prev = NULL, *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        ListNode *new_head = reverseLinkedList(head);
        ListNode *temp_head = new_head, *last;
        int carry = 1;
        while(carry && new_head){
            new_head->val++;
            carry = new_head->val / 10;
            new_head->val %= 10;
            last = new_head;
            new_head = new_head->next;
        }
        if(carry){
            last->next = new ListNode(1);
        }
        return reverseLinkedList(temp_head);
    }
};