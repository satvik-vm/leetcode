#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    vector<int> freq_words2(26,0);

    for(auto word2 : words2){
        vector<int> temp_words2(26,0);
        for(auto ch : word2){
            temp_words2[ch - 'a']++;
            freq_words2[ch - 'a'] = max(freq_words2[ch - 'a'], temp_words2[ch - 'a']);
        }
    }

    for(auto word1 : words1){
        vector<int> freq_word1(26, 0);
        bool flag = true;

        for(auto ch : word1){
            freq_word1[ch - 'a']++;
        }
        for(int i = 0;i < 26;i++){
            if(freq_words2[i] > freq_word1[i]){
                flag = false;
                break;
            }
        }
        if(flag)    ans.push_back(word1);
    }
    return ans;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e", "o"};

    time_start = chrono::high_resolution_clock::now();
    vector<string> ans = wordSubsets(words1, words2);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    for(auto str : ans) cout << str << " ";
    cout << endl;
    cout << time_diff.count() << " microseconds" << endl;
}