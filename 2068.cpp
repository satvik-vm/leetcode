#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> freq1(26, 0), freq2(26, 0);
    for(auto ch : word1)    freq1[ch - 'a']++;
    for(auto ch : word2)    freq2[ch - 'a']++;
    for(int i = 0;i < 26; i++){
        if((max(freq1[i], freq2[i]) - min(freq1[i], freq2[i])) > 3)   return false;
    }
    return true;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    string word1 = "abcdeef";
    string word2 = "abaaacc";

    time_start = chrono::high_resolution_clock::now();
    bool ans = checkAlmostEquivalent(word1, word2);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    cout << ans << endl;
    cout << time_diff.count() << " microseconds" << endl;
}