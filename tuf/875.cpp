#include <bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int data;
	ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
	ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

class Solution
{
public:
    ListNode *arrayToDoublyLinkedList(vector<int> &arr) {
        // Your code goes here
        // if(arr.size() == 0) return NULL;
        ListNode *prev = NULL, *head = NULL;
        for(int i = 0; i < arr.size(); i++){
            ListNode *new_node = new ListNode(arr[i], prev, NULL);
            if(prev) prev->next = new_node;
            else head = new_node;
            prev = new_node;
        }
        return head;
    }
};