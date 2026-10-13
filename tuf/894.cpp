#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class LinkedListQueue {
    ListNode *head, *curr;
public:
    LinkedListQueue() {
        head = NULL;
        curr = head;
    }

    void push(int x) {
        if(!head){
            head = new ListNode(x);
            curr = head;
            return;
        }
        if(curr->next){
            curr = curr->next;
            curr->val = x;
            return;
        }
        curr->next = new ListNode(x);
        curr = curr->next;
    }

    int pop() {
        int to_return = head->val;
        head = head->next;
        return to_return;
    }

    int peek() {
        int to_return = head->val;
        return to_return;
    }

    bool isEmpty() {
        return head == NULL;
    }
};