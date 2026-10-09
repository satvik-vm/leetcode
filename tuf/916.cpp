#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        map<int, int> mp;
        vector<vector<int>> sol;
        while(head){
            if(mp.find(head->val) != mp.end()) sol.push_back({mp[head->val], head->val});
            else if(target - head->val > 0) mp[target - head->val] = head->val;
            head = head->next;
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};