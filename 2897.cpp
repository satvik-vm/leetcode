#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        vector<int> count_bits(30, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 30; j++){
                if(nums[i] & (1 << j)) count_bits[j]++;
            }
        }

        long long answer = 0;
        vector<int> final_nums;
        for(int i = 0; i < k; i++){
            int num = 0;
            for(int j = 0; j < 30; j++){
                if(count_bits[j] > 0){
                    num |= (1 << j);
                    count_bits[j]--;
                }
            }
            final_nums.push_back(num);
        }

        for(int i =  0; i < k; i++){
            long long num = final_nums[i];
            answer = answer + (num * num % MOD);
        }

        return answer % MOD;
    }
};