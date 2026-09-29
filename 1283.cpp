#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            end = max(end, nums[i]);
        }
        while(start <= end){
            int mid = (start + end) / 2;
            int divided = 0;
            for(int i = 0; i < nums.size(); i++){
                divided += (nums[i] / mid) + (nums[i] % mid > 0);
            }
            if(divided <= threshold){
                end = mid - 1;
            }
            else{
				start = mid + 1;
			}
        }
        return start;
    }
};