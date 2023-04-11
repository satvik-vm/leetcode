#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string removeStars(string s) {
    string answer = "";
    answer += s[0];
    int i = 1;
    while(i < s.size()){
        if(s[i]=='*'){
            i++;
            answer.pop_back();
        }
        else{
            answer += s[i];
            i++;
        }
        // cout << answer << endl;
    }
    return answer;
}

int main(){
    string s = "erase*****";
    cout << removeStars(s) << endl;
    return 0;
}