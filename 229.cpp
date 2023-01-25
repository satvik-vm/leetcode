#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> answer;

    for(auto num: nums){
        map[num]++;
    }

    for(auto [first, second]: map){
        if(second > nums.size() / 3){
            answer.push_back(first);
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {1, 2};
    vector<int> answer = majorityElement(nums);

    for(auto itt: answer){
        cout << itt << " ";
    }
    cout << endl;
}