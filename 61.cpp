#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head ==  NULL || k == 0) return head;
    int len = 0;
    ListNode *curr = head;
    while(curr->next){
        curr = curr->next;
        len++;
    }
    len++;

    k = k % len;

    int pointer = len - k - 1;
    curr = head;

    while(pointer--){
        curr = curr->next;
    }

    ListNode *next_node, *head_1;
    if(curr->next){
        next_node = curr->next;
        head_1 = next_node;
    }
    else    return head;

    curr->next = NULL;

    while(next_node->next){
        next_node = next_node->next;
    }

    next_node->next = head;

    return head_1;
}

void addNode(ListNode *head, int data){
    ListNode *next_node = new ListNode(data);
    ListNode *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = next_node;
}

int main(){
    ListNode *head = new ListNode(1);
    // addNode(head, 1);
    // addNode(head, 2);
    // addNode(head, 4);
    // addNode(head, 5);

    ListNode *curr = rotateRight(head, 1);
    while(curr->next){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << curr->val << endl;
}