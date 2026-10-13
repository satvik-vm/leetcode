#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        vector<int> reverse_sort = nums;
        sort(nums.begin(), nums.end());
        sort(reverse_sort.rbegin(), reverse_sort.rend());

        int num_negative = nums.size() / 2;
        int num_positive = nums.size() - num_negative;

        long long neg_sum = 0;
        for(int i = 0; i < num_negative; i++){
            neg_sum += nums[i] * nums[i];
        }

        long long pos_sum = 0;
        for(int i = 0; i < num_positive; i++){
            pos_sum += reverse_sort[i] * reverse_sort[i];
        }

        return pos_sum - neg_sum;
    }
};