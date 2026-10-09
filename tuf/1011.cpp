#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    void deleteNode(ListNode* head){
        head->prev->next = head->next;
        if(head->next){
            head->next->prev = head->prev;
        }
        delete head;
    }

    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        if(!head)   return head;
        // ListNode *temp_home = new ListNode;
        ListNode temp_home;
        temp_home.next = head;
        head->prev = &temp_home;

        while(head){
            ListNode *next = head->next;
            if(head->val == target){
                deleteNode(head);
            }
            head = next;
        }

        if(temp_home.next) temp_home.next->prev = NULL;
        return temp_home.next;
    }
};