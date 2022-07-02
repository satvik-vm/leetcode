#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

vector<string> ans;

map<char, string> phoneletters = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
};

void util(string digits, int index, string current){
    if(index == digits.length())    ans.push_back(current);
    else{
        string letters = phoneletters[digits[index]];
        for(auto letter : letters){
            util(digits, index+1, current+letter);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.length() != 0){
        util(digits, 0, "");
    }
    return ans;
}

int main(){
    string digits = "2";
    vector<string> result = letterCombinations(digits);
    for(auto answer : result){
        cout << answer << " ";
    }
    cout << endl;
    cout << result.size() << endl;
}