#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr_result = {};
        vector<vector<int>> result = {};
        recur(result, curr_result, nums, 0);
        return result;
    }

    void recur(vector<vector<int>>& result, vector<int>& curr_result, vector<int>& nums, int index){
        result.push_back(curr_result);
        for(int i = index; i < nums.size(); i++){
            curr_result.push_back(nums[i]);
            recur(result, curr_result, nums, i + 1);
            curr_result.pop_back();
        }
    }
};