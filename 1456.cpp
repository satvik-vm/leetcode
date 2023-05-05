#include <iostream>
#include <vector>
// #include <unordered_ma>

using namespace std;

int maxVowels(string s, int k) {
    int max = 0;

    for(int i = 0; i < k; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            max++;
        }
    }

    int local_max = max;
    int n = s.length();

    for(int i = k; i < s.length(); i++){
        if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u')   local_max--;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') local_max++;
        if(local_max > max) max = local_max;
    }

    return max;
}

int main(){
    string s = "leetcode";
    int k = 3;
    cout << maxVowels(s, k) << endl;
}