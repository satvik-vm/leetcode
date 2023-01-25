#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    vector<bool> occurence(size);
    for(int i = 0;i < size; i++){
        if(occurence[nums[i]]){
            return nums[i];
        }
        else{
            occurence[nums[i]] = true;
        }
    }
    return 0;
}

int main(){
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << findDuplicate(nums) << endl;
}