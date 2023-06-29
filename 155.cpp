#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(this->st.empty()){
           this->st.push({val, val});
           return;
        }
        this->st.push({val, min(this->st.top().second, val)});
    }
    
    void pop() {
        this->st.pop();
    }
    
    int top() {
        return this->st.top().first;
    }
    
    int getMin() {
        return this->st.top().second;
    }
};


int main(){
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;
}