#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

using namespace std;

bool isAnagram(string s, string t) {
    if(t.length() == 0 || s.length() != t.length())  return false;
    unordered_map<char, int> maps, mapt;
    for(int i = 0; i < s.length(); i++){
        maps[s[i]]++;
        mapt[t[i]]++;
    }
    for(auto map_s : maps){
        if(map_s.second != mapt[map_s.first])   return false;
    }
    return true;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;
    string s = "cat";
    string t = "rat";
    time_start = chrono::high_resolution_clock::now();
    bool ans = isAnagram(s, t);
    time_end = chrono::high_resolution_clock::now();
    cout << s << " and " << t;
    if(ans) cout << " are anagram" << endl;
    else cout << " are not anagram" << endl;
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << "Done [" << time_diff.count() << " microseconds]" << endl << endl;
}