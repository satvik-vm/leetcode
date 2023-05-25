#include <iostream>
#include <vector>

using namespace std;

void utils(vector<int> &nums, vector<vector<int>> &result, int index){
    if(index == nums.size()){
        result.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        utils(nums, result, index+1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    utils(nums, result, 0);
    return result;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = permute(nums);
    for(auto itt1: result){
        for(int itt2: itt1) cout << itt2 << " ";
        cout << endl;
    }
}