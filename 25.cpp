#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k == 1)  return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy, *curr = dummy, *nex = dummy;
    int len = 0;

    while(curr->next){
        len++;
        curr = curr->next;
    }

    while(len >= k){
        curr = prev->next;
        nex = curr->next;

        for(int i = 1;i < k; i++){
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }

        prev = curr;
        len -= k;
    }
    return dummy->next;
}

void addNode(ListNode* head, int val){
    ListNode *next_node = new ListNode(val), *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = next_node;
}

int main(){
    ListNode *head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    ListNode *curr = head;
    while(curr->next){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << curr->val << endl;
    ListNode *answer = reverseKGroup(head, 3);
    while(answer->next){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << answer->val << endl;
}