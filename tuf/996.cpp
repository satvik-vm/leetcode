#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return recur(nums, k, 0, 0);
    }

    bool recur(vector<int>& nums, int k, int index, int curr_sum){
        if(k == curr_sum)   return true;
        if(index == nums.size() || curr_sum > k)    return false;
        bool answer = recur(nums, k, index + 1, curr_sum) || recur(nums, k, index + 1, curr_sum + nums[index]);
        return answer;
    }
};