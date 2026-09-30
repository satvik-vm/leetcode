#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int answer = 0, balance = 0;
        for(char ch: s){
            if(ch == '('){
                balance++;
                answer = max(answer, balance);
            }
            else if(ch == ')'){
                balance--;
            }
        }
        return answer;
    }
};