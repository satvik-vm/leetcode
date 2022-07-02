#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0){
        return "";
    }
    sort(strs.begin(), strs.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });
    string str = strs[0];
    for(int i = 1; i < strs.size();i++){
        for(int j = 0;j < str.length();j++){
            if(j == strs[i].length() || str[j] != strs[i][j]){
                str = str.substr(0, j);
                break;
            }
        }
    }
    return str;
}

int main(){
    vector<string> strs = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs) << endl;
}