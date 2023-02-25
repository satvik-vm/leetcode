#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int reversePairs(vector<int>& nums) {
    vector<vector<int>> answers;
    int answer = 0;
    int size = nums.size();
    for(int i = 0;i < size; i++){
        for(int j = i + 1;j < size; j++){
            if(2 * nums[j] > INT32_MAX){
                continue;
            }
            else if(nums[i] > result){
                answers.push_back({i, j});
                answer++;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {2,4,3,5,1};
    int answer = reversePairs(nums);
    cout << answer << endl;
}