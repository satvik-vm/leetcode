#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {};
};

ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next)    return NULL;
    ListNode *fast = head, *slow = head;
    bool cycle = false;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            cycle = true;
            slow = head;
            break;
        }
    }
    if(cycle){
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    return NULL;
}

void addNode(ListNode *head, int val){
    ListNode *next_node = new ListNode(val);
    while(head->next){
        head = head->next;
    }
    head->next = next_node;
}

int main(){
    ListNode *head = new ListNode(1);
    addNode(head, 2);
    ListNode *answer = detectCycle(head);
    if(answer)  cout << answer->val << endl;
    else    cout << -1 << endl;
}