#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <chrono>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    for(int i = 0;i < words.size();i++){
        bool flag = true;
        vector<int> wordnum(26, -1);
        vector<int> patternum(26, -1);
        for(int j = 0;j < pattern.size();j++){
            int a = wordnum[words[i][j] - 'a'];
            int b = patternum[pattern[j] - 'a'];
            if(a == -1 || b == -1) {}
            if (a != b){
                flag = false;
                break;
            }
            wordnum[words[i][j] - 'a'] = j;
            patternum[pattern[j] - 'a'] = j;
        }
        if(flag)    ans.push_back(words[i]);
    }
    return ans;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    time_start = chrono::high_resolution_clock::now();
    vector<string> ans = findAndReplacePattern(words, pattern);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    for(auto str : ans) cout << str << " ";
    cout << endl;
    cout << "Done [" << time_diff.count() << " microseconds]" << endl << endl;
}