#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#define NO_OF_CHARS 256

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
 
    int res = 0; // result
    vector<int> lastIndex(NO_OF_CHARS, -1);
    int i = 0;
 
    for (int j = 0; j < n; j++) {
        i = max(i, lastIndex[s[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[s[j]] = j;
    }
    return res;
}

int main(){

}