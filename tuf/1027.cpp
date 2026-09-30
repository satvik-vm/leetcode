#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseStack(stack<int> &st) {
        // Your code goes here
        if(st.empty())  return;
        int top = st.top();
        st.pop();
        reverseStack(st);
        insertElement(st, top);
        return;
    }

    void insertElement(stack<int>& st, int num){
        if(st.empty()){
            st.push(num);
            return;
        }
        int top = st.top();
        st.pop();
        insertElement(st, num);
        st.push(top);
    }
};