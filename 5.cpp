#include <iostream>
#include <cstring>

using namespace std;

string longestPalindrome(string s) {
    int size = s.size();

    bool isPalindrome[size][size];

    memset(isPalindrome, 0, sizeof(isPalindrome));

    int maxLength = 1;
    for(int i = 0;i < size;i++) {
        isPalindrome[i][i] = true;
    }

    int start = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
            maxLength = 2;
            start = i;
            maxLength = 2;
        }
    }

    for(int i = 3; i <= size; ++i) {
        for(int j = 0; j < size - i + 1; ++j){
            int k = i + j - 1;
            cout << "j: " << j << " i: " << i << " k:" << k << endl;
            if(isPalindrome[j+1][k-1] && s[j] == s[k]){
                isPalindrome[j][k] = true;
                if(i > maxLength){
                    start = j;
                    maxLength = i;
                }
            }
        }
    }

    cout << maxLength << endl;

    string str = s.substr(start, maxLength);
    return str;
}

int main(){
    string s = "cbbd";
    string str = longestPalindrome(s);
    cout << str << endl;
}