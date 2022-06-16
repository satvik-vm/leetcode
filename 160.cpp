#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next = NULL;
};

int getcount(ListNode *home){
    ListNode *curr =home;
    int count = 0;
    while(curr->next != NULL){
        count++;
        curr = curr->next;
    }
    count++;
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int m = getcount(headA);
    int n = getcount(headB);
    ListNode *curr1 = headA;
    ListNode *curr2 = headB;
    if(m > n){
        for(int i = 0;i < m-n;i++){
            curr1 = curr1->next;
        }
    }
    if(n > m){
        for(int i = 0;i < n-m;i++){
            curr2 = curr2->next;
        }
    }
    cout << m << " " << n << endl;
    cout << curr1->val << " " << curr2->val << endl;
    while(curr1->next != NULL && curr2->next != NULL){
        if(curr1->val == curr2->val) {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}

void addnode(ListNode *home, int val){
    ListNode *curr1 = home;
    ListNode *curr = new ListNode;
    curr->val = val;
    while(curr1->next != NULL){
        curr1 = curr1->next;
    }
    curr1->next = curr;
}

int main(){
    ListNode *headA = new ListNode;
    headA->val = 4;
    addnode(headA, 1);
    addnode(headA, 8);
    addnode(headA, 4);
    addnode(headA, 5);
    ListNode *headB = new ListNode;
    headB->val = 5;
    addnode(headB, 6);
    addnode(headB, 1);
    addnode(headB, 8);
    addnode(headB, 4);
    addnode(headB, 5);
    ListNode *ans = getIntersectionNode(headA, headB);
    while(ans->next != NULL){
        cout << ans->val << endl;
        ans = ans->next;
    }
    cout << ans->val << endl;
}