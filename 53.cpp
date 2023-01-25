#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0, __max = nums[0];    
    for(int i = 0;i < nums.size(); i++){
        sum += nums[i];
        __max = max(__max, sum);
        if(sum < 0) sum = 0;
    }
    return __max;
}

int main(){
    vector<int> nums = {1};
    cout << maxSubArray(nums) << endl;
}