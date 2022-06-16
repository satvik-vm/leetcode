#include <iostream>
#include <cstring>

using namespace std;

int reverse(int x) {
    if(x == INT32_MIN || x == INT32_MAX)    return 0;
    int flag = (x < 0) ? -1 : 1;
    // x *= flag;
    long long int a = x * flag;
    long long int reversed = 0;
    while(a){
        int rem = a % 10;
        reversed = reversed * 10 + rem;
        a /= 10;
    }
    reversed *= flag;
    if(reversed < INT32_MIN || reversed > INT32_MAX)    return 0;
    return reversed;
}

int main(){
    cout << reverse(-2147483648) << endl;
}