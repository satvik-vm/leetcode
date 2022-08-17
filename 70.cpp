#include <iostream>

using namespace std;

int dp[46] = {0};

int climbStairs(int n){
    if(n == 1)  return 1;
    if(n == 2)  return 2;
    if(dp[n] != 0) return dp[n];
    dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}

int main(){
    int n = 3;
    cout << climbStairs(n) << endl;
}