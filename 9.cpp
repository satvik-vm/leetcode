#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {
    string str = to_string(x);
    int size = str.length();
    int i, j;
    if(size % 2 == 0){
        i = size / 2;
        j = i - 1;
    }
    else{
        i = size / 2 + 1; 
        j = size / 2 - 1;
    }
    while(j >= 0 && i <= size-1 ){
        if(str[j] != str[i])    return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    int x = 121;
    cout << isPalindrome(x) << endl;
}