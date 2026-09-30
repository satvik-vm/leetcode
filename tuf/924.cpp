#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
        vector<string> ans;
        recur(n, ans, "", 0);
        return ans;
    }

    void recur(int n, vector<string>& ans, string curr, int index){
        if(index == n){
            ans.push_back(curr);
            return;
        }
        bool is_one = curr[curr.size() - 1] == '1' ? true : false;
        // cout << curr << " " << is_one << endl;
        recur(n, ans, curr + '0', index + 1);
        if(!is_one){
            recur(n, ans, curr + '1', index + 1);
        }
    }
};
