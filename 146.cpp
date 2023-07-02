#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node{
    int val, key;
    Node *next, *prev;
    Node(int x_key, int x_value) : key(x_key), val(x_value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity, size;
    map<int, Node*> mp;
    Node *head = NULL, *tail = NULL;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->size = 0;
    }

    void deleteNode(Node *to_delete){
        to_delete->prev->next = to_delete->next;
		to_delete->next->prev = to_delete->prev;
        mp.erase(to_delete->key);
    }

    void addNode(Node *to_add){
		if(mp.find(to_add->key) != mp.end()){
			deleteNode(mp[to_add->key]);
		}
		mp[to_add->key] = to_add;
		Node *tailPrev = tail->prev;
		tailPrev->next = to_add;
		tail->prev = to_add;
		to_add->next = tail;
		to_add->prev = tailPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node *node = new Node(key, value);
        addNode(node);
        size = mp.size();
        if(size > capacity){
            deleteNode(head->next);
            size--;
        }
    }
};

int main(){
	LRUCache *obj = new LRUCache(2);
	obj->put(2,1);
	obj->put(1,1);
	obj->put(2,3);
	obj->put(4,1);
	cout << obj->get(1) << endl;
	cout << obj->get(2) << endl;
}