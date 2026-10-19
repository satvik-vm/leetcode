#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> digit_sum(int x){
        int temp = x, digit = 0;
        for(;temp > 0; temp /= 10){
            digit += temp % 10;
        }
        return {digit, x};
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> digits(n);

        for(int i = 0; i < n; i++){
            digits[i] = digit_sum(nums[i]);
        }

        sort(digits.begin(), digits.end());

        unordered_map<int, int> ranks;
        for(int i = 0; i < n; i++){
            ranks[digits[i][1]] = i;
        }

        vector<int> home(n);
        for(int i = 0; i < n; i++){
            home[i] = ranks[nums[i]];
        }

        int swaps = 0;
        for(int i = 0; i < n; i++){
            while(home[i] != i){
                swap(home[i], home[home[i]]);
                swaps++;
            }
        }

        return swaps;
    }
};