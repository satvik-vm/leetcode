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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count_nodes = 0;
        ListNode *temp_head = head;
        while(head){
            count_nodes++;
            head = head->next;
        }
        head = temp_head;
        int from_start = count_nodes - n;
        if(from_start == 0) return head->next;
        from_start--;
        while(from_start-- > 0){
            head = head->next;
        }
        head->next = head->next->next;
        return temp_head;
    }
};