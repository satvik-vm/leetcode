#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        if(s.size() == 1)   return map[s[0]];
        int answer = 0;
        bool last_taken = false;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size() - 1){
                if(map[s[i]] < map[s[i+1]]){
                    answer += map[s[i+1]] - map[s[i]];
                    if(i+1 == s.size() - 1) last_taken = true;
                    i++;
                }
                else{
                    answer += map[s[i]];
                }
                cout << answer << endl;
            }
        }
        if(!last_taken) answer += map[s[s.size() - 1]];
        return answer;
    }
};