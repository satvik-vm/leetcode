#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    vector<int> vec;
    while(head->next){
        vec.push_back(head->val);
        head = head->next;
    }
    vec.push_back(head->val);
    int size = vec.size();
    // for(auto itt: vec)  cout << itt << " ";
    // cout << endl;
    long long unsigned int max_pair = 0;
    for(int i = 0; i < size/2; i++){
        long long unsigned int max_val = vec[i] + vec[size - i -1];
        max_pair = max(max_pair, max_val);
        // cout << max_val << " " << vec[i] << " " << vec[size - i - 1] << " "; 
    }
    return max_pair;
}

void addNode(ListNode *head, int val){
    ListNode *next_node = new ListNode(val);
    ListNode *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = next_node;
}

int main() {
    ListNode *head = new ListNode(4);
    addNode(head, 2);
    addNode(head, 2);
    addNode(head, 3);
    cout << pairSum(head) << endl;
}