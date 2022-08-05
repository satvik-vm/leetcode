#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> dp;

int util(vector<int>& nums, int target){
    if(target == 0) return 1;
    if(dp[target] != -1)    return dp[target];
    int ans = 0;
    for(auto num : nums){
        if(num <= target){
            ans += util(nums, target - num);
        }
    }
    return dp[target] = ans;
}

int combinationSum4(vector<int>& nums, int target) {
    dp.resize(target + 1, -1);
    return util(nums, target);
}

int main(){
    vector<int> nums = {3};
    int target = 9;
    cout << combinationSum4(nums, target) << endl;
}