#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string convert(string s, int numRows) {
    string substr[numRows];
    memset(substr, 0, sizeof(substr));
    int i = 0;
    while(i < s.length()){
        for(int j = 0; j < numRows && i < s.length(); j++){
            substr[j] += s[i];
            i++;
        }
        for(int j = numRows - 2; j > 0 && i < s.length(); j--){
            substr[j] += s[i];
            i++;
        }
    }
    for(int i = 1; i < numRows; i++){
        substr[0] += substr[i];
    }
    return substr[0];
}

int main(){
    cout << convert("PAYPALISHIRING", 4) << endl;
}