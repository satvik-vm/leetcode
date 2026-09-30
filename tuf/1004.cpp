#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        return recur(nums, k, 0, 0);
    }

    int recur(vector<int>& nums, int k, int sum, int index){
        if(k == sum)   return 1;
        if(index == nums.size() || k < sum) return 0;
        int answer = recur(nums, k, sum + nums[index], index + 1) + recur(nums, k, sum, index + 1);
        return answer;
    }
};