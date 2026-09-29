#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int result = 0;
        string answer = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(result > 0) answer += s[i];
                result++;
            }
            if(s[i] == ')'){
                result--;
                if(result > 0) answer += s[i];
            }
        }
        return answer;
    }
};