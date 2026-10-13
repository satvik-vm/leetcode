#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
    int index;
    vector<int> q;
public:
    ArrayQueue() {
        this->index = 0;
    }

    void push(int x) {
        q.push_back(x);
    }

    int pop() {
        return this->q[this->index++];
    }

    int peek() {
        return this->q[this->index];
    }

    bool isEmpty() {
        return this->index == this->q.size();
    }
};