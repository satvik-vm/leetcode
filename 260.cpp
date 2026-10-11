#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstSetBit(int x){
        int i = 0;
        while(x){
            if(x & 1) return i;
            x >>= 1;
            i++;
        }
        return -1;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int _xor = nums[0];
        for(int i = 1; i < nums.size(); i++){
            _xor ^= nums[i];
        }

        int index = firstSetBit(_xor);

        vector<int> set_half, unset_half;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >> index & 1)    set_half.push_back(nums[i]);
            else unset_half.push_back(nums[i]);
        }

        int num_one = set_half[0], num_two = unset_half[0];
        for(int i = 1; i < set_half.size(); i++){
            num_one ^= set_half[i];
        }

        for(int i = 1; i< unset_half.size(); i++){
            num_two ^= unset_half[i];
        }

        return {num_one, num_two};
    }
};