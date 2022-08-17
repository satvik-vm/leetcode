#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map, index;
    vector<int> ans;
    for (int i = 0; i < nums.size();i++){
        map[nums[i]] = target - nums[i];
    }
    for (int i = 0; i < nums.size();i++){
        index[nums[i]] = i;
    }
    for(int i = 0; i < nums.size();i++){
        if(map.find(map[nums[i]]) != map.end() && index[map[nums[i]]] != i){
            ans.push_back(i);
            ans.push_back(index[map[nums[i]]]);
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    int a;
    // while(a != -999){
    //     cin >> a;
    //     nums.push_back(a);
    // }
    // nums.pop_back();
    // for(int i = 0; i < nums.size();i++){
    //     cout << nums[i] << endl;
    // }
    nums = {3, 3};
    int target = 6;
    vector<int> ans = twoSum(nums, target);
    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}