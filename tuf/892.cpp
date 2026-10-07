#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
	ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
	ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

class Solution {
public:
    ListNode *deleteTail(ListNode *&head) {
        if(head->next == NULL)   return NULL;
        ListNode *temp_head = head;
        while(head && head->next){
            head = head->next;
        }
        ListNode *temp = head->prev;
        head->prev = NULL;
        temp->next = NULL;
        return temp_head;
    }
};