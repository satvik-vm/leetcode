#include <iostream>
#include <cstring>

using namespace std;

int myAtoi(string s) {
    if(s.empty()) return 0;
    int i = 0;
    while(s[i] == ' '){
        i++;
    }
    s = s.substr(i);
    int flag = s[0] == '-' ? -1 : 1;

    if (s[0] == '+' || s[0] == '-'){
        s = s.substr(1);
    }

    long long int ans = 0;

    for(auto str : s){
        if(!isdigit(str))   break;
        ans = (ans * 10) + int(str - '0');
        if(flag * ans < INT32_MIN)  return INT32_MIN;
        if(flag * ans > INT32_MAX)  return INT32_MAX;
    }

    return flag * ans;
}

int main(){
    string s = "4193 with words";
    cout << myAtoi(s) << endl;
}