#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
    if(!head)   return head;
    vector<int> nums;
    while(head){
        nums.push_back(head->val);
        head = head->next;
    }
    sort(nums.begin(), nums.end());
    ListNode *new_head = new ListNode(nums[0]);
    ListNode *to_return = new_head;
    for(int i = 1;i < nums.size();i++){
        new_head->next = new ListNode(nums[i]);
        new_head = new_head->next;
    }
    return to_return;
}

int main(){
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    ListNode *new_head = sortList(head);
    while(new_head){
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    return 0;
}