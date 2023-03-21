#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode    (int x): val(x), next(NULL) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    int itt1 = 0;
    ListNode *node_a = NULL, *node_b = NULL, *home = list1;
    while(itt1 < a-1 && list1 != NULL){
        list1 = list1->next;
        itt1++;
    }
    node_a = list1;
    while(itt1 < b && list1 != NULL){
        list1 = list1->next;
        itt1++;
    }
    node_b = list1;
    node_a->next = list2;
    while(list2->next != NULL){
        list2 = list2->next;
    }
    list2->next = node_b->next;
    node_b->next = NULL;
    return home;
}

void addNode(ListNode *home, int val){
    ListNode *next = new ListNode(val);
    ListNode *curr = home;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = next;
}

void print(ListNode *list){
    while(list->next != NULL){
        cout << list->val << " ";
        list = list->next;
    }
    cout << list->val << endl;
}

int main(){
    ListNode *list1 = new ListNode(0);
    addNode(list1, 1);
    addNode(list1, 2);
    addNode(list1, 3);
    addNode(list1, 4);
    addNode(list1, 5);
    addNode(list1, 6);


    ListNode *list2 = new ListNode(1000000);
    addNode(list2, 1000001);
    addNode(list2, 1000002);
    addNode(list2, 1000002);
    addNode(list2, 1000003);
    addNode(list2, 1000004);


    int a = 2, b = 5;

    print(mergeInBetween(list1, a, b, list2));
}

