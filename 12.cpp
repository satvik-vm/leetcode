#include <iostream>
#include <cstring>

using namespace std;

string intToRoman(int num) {
    string thousand[] = {"", "M", "MM", "MMM"};
    string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string ans = thousand[num / 1000] + hundred[(num / 100) % 10] + ten[(num / 10) % 10] + one[num % 10];
    return ans;
}

int main(){
    cout << intToRoman(1994) << endl;
}
