#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());
    vector<int> result;
    vector<vector<int>> dp(nums.size());
        
    for(int i = 0;i<nums.size();i++){
        for(int j = 0;j<i;j++){
            if(nums[i]%nums[j] == 0 && dp[j].size()>dp[i].size()){
                dp[i] = dp[j];
            }
        }
        dp[i].push_back(nums[i]);
        if(result.size()<dp[i].size())	result = dp[i];
    }

    return result;
}

int main(){
	vector<int> nums = {1, 2, 3};
	vector<int> result = largestDivisibleSubset(nums);
	for(int itt: result){
		cout << itt << " ";
	}
	cout << endl;
}