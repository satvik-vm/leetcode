#include <iostream>

using namespace std;

int tribonacci(int n) {
    int dp[3]={0,1,1};
    for(auto i=3;i<=n;i++)
        dp[i%3]=dp[0]+dp[1]+dp[2];
    
    return dp[n%3];
}

int main(){
    int n = 34;
    cout << tribonacci(n) << endl;
}