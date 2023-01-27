#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answers;
    for(int i = 0;i < size; i++){
        for(int j = i + 1;j < size; j++){
            int left = j + 1;
            int right =  size - 1;
            int __target = target - nums[i] - nums[j];
            while(left < right){
                int num = nums[left] + nums[right];
                if(__target > num){
                    left++;
                }
                else if(__target < num){
                    right--;
                }
                else if(__target == num){
                    vector<int> current_answer;
                    current_answer.push_back(nums[i]);
                    current_answer.push_back(nums[j]);
                    current_answer.push_back(nums[left]);
                    current_answer.push_back(nums[right]);
                    answers.push_back(current_answer);
                    while(left < right && nums[left] == current_answer[2])  left++;
                    while(left < right && nums[right] == current_answer[3]) right--;
                }
            }
            while(j + 1 < size && nums[j+1] == nums[j]) j++;
        }
        while(i + 1 < size && nums[i + 1] == nums[i])   i++;
    }
    return answers;
}

int main(){
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    vector<vector<int>> answer = fourSum(nums, target);
    for(auto itt1: answer){
        for(int itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}