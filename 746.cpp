#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int *dp = new int[n];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2;i < n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int ans = minCostClimbingStairs(cost);
    cout << "ans: " << ans << endl;
}