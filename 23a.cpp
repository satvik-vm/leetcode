#include <bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<int> nums;
        unordered_map<int, stack<ListNode*>> mp;

        for(int i = 0; i < lists.size(); i++){
            if(!lists[i]) continue;
            nums.insert(lists[i]->val);
            mp[lists[i]->val].push(lists[i]);
        }

        ListNode *head = new ListNode, *temp_head = head;

        while(!nums.empty()){
            int num_to_insert = *nums.begin();
            ListNode *insert = mp[num_to_insert].top();
            head->next = insert;
            mp[num_to_insert].pop();
            if(mp[num_to_insert].empty())   nums.erase(num_to_insert);
            ListNode *next = insert->next;
            if(next){
                nums.insert(next->val);
                mp[next->val].push(next);
            }
            head = head->next;
        }
        return temp_head->next;
    }
};