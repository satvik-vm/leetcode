#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        return recur(str, 0, 0, n);
    }

    vector<string> recur(string str, int closed_used, int open_used, int n){
        if(closed_used == n && closed_used == open_used){
            return {str};
        }

        vector<string> to_return = {};

        if(open_used < n){
            vector<string> open = recur(str + '(', closed_used, open_used + 1, n);
            to_return.insert(to_return.end(), open.begin(), open.end());
        }

        if(closed_used < open_used){
            vector<string> close = recur(str + ')', closed_used + 1, open_used, n);
            to_return.insert(to_return.end(), close.begin(), close.end());
        }

        return to_return;
    }
};