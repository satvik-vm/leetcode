#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int>& nums, int target, int start, int end){
    if(nums.size() == 0)    return -1;
    if(nums.size() == 1)    nums[0] == target ? 0 : -1;
    if(start <= end){
        int mid = (start + end) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target)  return utils(nums, target, start, mid - 1);
        if(nums[mid] < target)  return utils(nums, target, mid + 1, end);
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    return utils(nums, target, 0, nums.size());
}

int main(){
    vector<int> nums = {-1};
    int target = 2;
    cout << search(nums, target) << endl;
}