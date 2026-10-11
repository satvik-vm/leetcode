#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setRightmostUnsetBit(int n) {
        // Your code goes here
        int index = 0;
        int copy = n;
        while(n){
            if(!(n & 1)) break;
            n >>= 1;
            index++;
        }
        return copy | (1 << index);
    }
};