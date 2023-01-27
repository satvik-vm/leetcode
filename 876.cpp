#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next){
        slow = slow->next;
        if(fast->next->next)    fast = fast->next->next;
        else    fast = fast->next;
    }
    return slow;
}

void addNode(ListNode *home, int val){
    ListNode *next = new ListNode;
    next->val = val;
    next->next = NULL;
    ListNode *curr = home;
    while(curr->next)   curr = curr->next;
    curr->next = next;
}

int main(){
    ListNode *head = new ListNode;
    head->val = 1;
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    addNode(head, 6);
    cout << "List formed" << endl;
    ListNode *answer = middleNode(head);
    while(answer->next){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << answer->val;
    cout << endl;
}