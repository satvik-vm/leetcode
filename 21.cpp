#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

void addListNode(ListNode *home, int val){
    // ListNode *curr = home;
    ListNode *next = new ListNode;
    next->val = val;
    while(home->next)   home = home->next;
    home->next = next;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *ans = new ListNode;
    ListNode *pt = ans;
    while(list1 != NULL && list2 != NULL) {
        if(list1->val < list2->val){
            addListNode(ans, list1->val);
            list1 = list1->next;
        }
        else{
            addListNode(ans, list2->val);
            list2 = list2->next;
        }
    }
    if(list1 == NULL){
        while(list2 != NULL){
            addListNode(ans, list2->val);
            list2 = list2->next;
        }
    }
    else if(list2 == NULL){
        while(list1 != NULL){
            addListNode(ans, list1->val);
            list1 = list1->next;
        }
    }
    ans = pt->next;
    return ans;
}

int main(){
    ListNode *list1 = new ListNode;
    ListNode *pt1 = list1;
    ListNode *list2 = new ListNode;
    ListNode *pt2 = list2;

    // list1->val = 1;
    // list2->val = 1;

    // addListNode(list1, 2);
    // addListNode(list1, 4);
    // addListNode(list2, 3);
    // addListNode(list2, 4);

    list1 = pt1;
    list2 = pt2;

    ListNode *ans = mergeTwoLists(list1, list2);

    while(ans != NULL){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}
