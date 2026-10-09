#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
   	ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode *temp = head;
        int len = 1;
        while(temp->next){
            len++;
            temp = temp->next;
        }

        len /= 2;
        len--;

        temp = head;
        while(len--){
            head = head->next;
        }
        head->next = head->next->next;

        return temp;
    }
};