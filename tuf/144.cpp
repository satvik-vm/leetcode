#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    vector<int> s;
    int index;
public:
    ArrayStack() {
        // vector<int> s;
        this->index = -1;
    }

    void push(int x) {
        this->index++;
        if(this->index < this->s.size())    s[index] = x;
        else    s.push_back(x);
    }

    int pop() {
        return this->s[this->index--];
    }

    int top() {
        return this->s[this->index];
    }

    bool isEmpty() {
        return this->index == -1;
    }
};