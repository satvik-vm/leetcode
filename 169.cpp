#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int size = nums.size();
    for(int i = 0;i < size; i++){
        map[nums[i]]++;
    }
    int answer = -1;
    for(auto itt: map){
        if(itt.second > size / 2){
            answer = itt.first;
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;
}