#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    int *dp = new int[n];
    dp[0] = nums[0];
    if(n > 1)   dp[1] = max(nums[0], nums[1]);
    if(n > 2)
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
    return dp[n-1];
}

int main(){
    vector<int> nums = {0};
    int ans = rob(nums);
    cout << ans << endl;
}