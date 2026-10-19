#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int priority(char ch){
        if(ch == '-' || ch == '+')  return 0;
        if(ch == '*' || ch == '/')  return 1;
        if(ch == '^')   return 2;
    }

    string infixToPostfix(string s) {
        // Your code goes here
        string answer = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')){
                answer += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    answer += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else {
                while (!st.empty() && st.top() != '(' &&
                    (priority(s[i]) < priority(st.top()) ||
                        (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
                    answer += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;
    }
};