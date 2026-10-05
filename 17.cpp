#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, vector<char>> map;
public:
    vector<string> letterCombinations(string digits) {
        map['2'] = vector<char>{'a', 'b', 'c'};
        map['3'] = vector<char>{'d', 'e', 'f'};
        map['4'] = vector<char>{'g', 'h', 'i'};
        map['5'] = vector<char>{'j', 'k', 'l'};
        map['6'] = vector<char>{'m', 'n', 'o'};
        map['7'] = vector<char>{'p', 'q', 'r', 's'};
        map['8'] = vector<char>{'t', 'u', 'v'};
        map['9'] = vector<char>{'w', 'x', 'y', 'z'};

        vector<string> answer;
        string curr = "";
        recur(digits, 0, answer, curr);
        return answer;
    }

    void recur(string digits, int index, vector<string>& answer, string& curr){
        if(index == digits.size()){
            answer.push_back(curr);
            return;
        }

        vector<char> curr_chars = map[digits[index]];

        for(int i = 0; i < curr_chars.size(); i++){
            curr += curr_chars[i];
            recur(digits, index + 1, answer, curr);
            curr.pop_back();
        }
    }
};

int main(){
    string digits = "2";
	Solution sol;
    vector<string> result = sol.letterCombinations(digits);
    for(auto answer : result){
        cout << answer << " ";
    }
    cout << endl;
    cout << result.size() << endl;
}