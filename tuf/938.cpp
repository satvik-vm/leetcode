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
    void deleteNode(ListNode *node){
        node->prev->next = node->next;
        if(node->next)  node->next->prev = node->prev;
        delete node;
    }

    ListNode * removeDuplicates(ListNode *head) {
        ListNode *temp_head = head;
        while(head->next){
            if(head->val == head->next->val){
                deleteNode(head->next);
            }
            else{
                head = head->next;
            }
        }
        return temp_head;
    }
};