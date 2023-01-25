#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void sortColors(vector<int>& nums) {
    unordered_map<int ,int> map;
    for(int i = 0;i < nums.size(); i++){
        map[nums[i]]++;
    }
    nums.clear();
    while(map[0]--){
        nums.push_back(0);
    }
    while(map[1]--){
        nums.push_back(1);
    }
    while(map[2]--){
        nums.push_back(2);
    }
}

int main(){
    vector<int> nums = {2, 0, 1};
    sortColors(nums);
    for(int itt: nums){
        cout << itt << " ";
    }
    cout << endl;
}