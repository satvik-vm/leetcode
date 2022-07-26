#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

int helper(vector<int>& nums, int target, bool left) {
    int start = 0, end = nums.size() - 1, middle, index = -1;
    while(start <= end){
        middle = (start + end) / 2;
        if(nums[middle] > target){
            end = middle - 1;
        }
        else if(nums[middle] < target){
            start = middle + 1;
        }
        else if(nums[middle] == target){
            index = middle;
            if(left){
                end = middle - 1;
            }
            else{
                start = middle + 1;
            }
        }
    }
    return index;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0)    return {-1, -1};
    vector<int> result = {helper(nums, target, true), helper(nums, target, false)};
    return result;
}



int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<int> vec = {5,7,7,8,8,10, 11, 11, 11, 12, 13, 14, 14, 15, 17, 17, 17, 17, 20, 20};
    int target = 16;

    time_start = chrono::high_resolution_clock::now();
    vector<int> ans = searchRange(vec, target);
    time_end = chrono::high_resolution_clock::now();

    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    for(int itt : ans){
        cout << itt << " ";
    }
    cout << endl;
    cout << "Done [" << time_diff.count() << " microseconds]" << endl;
}