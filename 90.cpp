#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> curr_answer;
        recur(nums, answer, curr_answer, 0);
        return answer;
    }

private:
    void recur(vector<int>& nums, vector<vector<int>>& answer, vector<int>& curr_answer, int index){
        answer.push_back(curr_answer);
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i - 1] == nums[i]) continue;
            curr_answer.push_back(nums[i]);
            recur(nums, answer, curr_answer, i + 1);
            curr_answer.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {4, 4, 4, 1, 4};
	Solution sol;
    vector<vector<int>> answers = sol.subsetsWithDup(nums);
    for(int i = 0; i < answers.size(); i++){
        for(int j = 0;j < answers[i].size(); j++){
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
}