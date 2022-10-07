#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
    int length = s.size();
    bool flag = true;
    for(int i = length - 1;i >= 0; i--){
        if(s[i] != ' ') flag = false;
        if(!flag && s[i] == ' ')    break;
        else if(s[i] != ' ') count++;
    }
    return count;
}

int main(){
    string str = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(str) << endl;
}

