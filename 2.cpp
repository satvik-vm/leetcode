#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

void adddata(ListNode *node1, int num){
    while(node1->next != NULL){
        node1 = node1->next;
    }
    ListNode *curr = new ListNode;
    curr->val = num;
    curr->next = NULL;
    node1->next = curr;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, length1 = 0, length2 = 0;
    ListNode ans, *pt = &ans, *temp1 = l1, *temp2 = l2;
    int result;
    while(l1->next != NULL){
        length1++;
        l1 = l1->next;
    }
    length1++;
    while(l2->next != NULL){
        length2++;
        l2 = l2->next;
    }
    length2++;
    l1 = temp1;
    l2 = temp2;
    while(length2 > length1){
        adddata(l1, 0);
        length1++;
    }
    while(length1 > length2){
        adddata(l2, 0);
        length2++;
    }
    l1 = temp1;
    l2 = temp2;
    while(ans.next != NULL) {
        ans = *ans.next;
    }
    for(int i = 0;i < length2;i++){
        result = l1->val + l2->val + carry;
        carry = result / 10;
        result %= 10;
        adddata(&ans, result);
        l1 = l1->next;
        l2 = l2->next;
    }
    if(carry > 0) {
        adddata(&ans, carry);
    }
    pt = pt->next;
    return pt;
}

int main(){
    ListNode node1, node2;
    node1.next = NULL;
    node2.next = NULL;
    adddata(&node1, 0);
    adddata(&node2, 0);
    node1 = *node1.next;
    node2 = *node2.next;
    ListNode *result = addTwoNumbers(&node1, &node2);
    while(result->next != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << result->val << endl;
}