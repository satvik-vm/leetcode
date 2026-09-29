#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> isNextPresent;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            isNextPresent[nums[i]] = true;
        }

        for(int i = 0; i < n; i++){
            if(isNextPresent.count(nums[i] + 1) == 0){
                isNextPresent[nums[i]] = false;
            }
        }

        int answer = 0;
        for(int i = 0; i < n; i++){
            int curr_answer = 1;
            int j = nums[i];
            if(!isNextPresent.count(j - 1)){
                while(isNextPresent[j]){
                    isNextPresent[j++] = false;
                    curr_answer++;
                }
            }
            answer = max(answer, curr_answer);
        }
        return answer;
    }
};