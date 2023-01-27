#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void addNode(ListNode *head, int next){
    ListNode *next_node = new ListNode(next);
    ListNode *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = next_node;
}

int main(){
    ListNode *head= new ListNode(4);
    addNode(head, 5);
    addNode(head, 1);
    addNode(head, 9);
    deleteNode(head->next->next);
    while(head->next){
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
}