#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007L

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n % 2){
            return (5 * myPow(20, n/2)) % MOD;
        }
        return myPow(20, n/2);
    }
    long long myPow(long long x, long long n){
        if(n == 0)  return 1;
        if(n % 2){
            return (x * myPow(x, n - 1)) % MOD;
        }
        else{
            return myPow((x*x) % MOD, n/2);
        }
    }
};