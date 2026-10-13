#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class LinkedListStack {
    ListNode *head, *curr;
public:
    LinkedListStack() {
        head = new ListNode;
        curr = head;
    }

    void push(int x) {
        if(curr->next){
            curr = curr->next;
            curr->val = x;
            return;
        }
        curr->next = new ListNode(x);
        curr = curr->next;
    }

    int pop() {
        ListNode *temp_head = head, *prev = temp_head;
        while(temp_head != curr){
            prev = temp_head;
            temp_head = temp_head->next;
        }
        int to_return = curr->val;
        curr = prev;
        return to_return;
    }

    int top() {
        return curr->val;
    }

    bool isEmpty() {
        return curr == head;
    }
};