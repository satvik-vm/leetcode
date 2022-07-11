#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void addNode(ListNode *head, int val)
{
    ListNode *curr = head;
    while (curr->next)
        curr = curr->next;
    ListNode *next = new ListNode;
    next->val = val;
    curr->next = next;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
    ListNode *head = new ListNode;
    cout << "Enter the linked list" << endl;
    int in, n;
    cin >> in;
    head->val = in;
    cin >> in;
    while (in != -999)
    {
        addNode(head, in);
        cin >> in;
    }
    cout << "Enter position from end : ";
    cin >> n;
    head = removeNthFromEnd(head, n);
    while (head->next)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
}
