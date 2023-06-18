#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int utils(vector<int>& nums, int start, int end, vector<vector<int>>& dp){
	if(start > end || nums.size() <= 0)	return 0;
	if(start < 0 || end >= nums.size())	return 1;
	if(dp[start][end] != -1)	return dp[start][end];

	int max_num = INT_MIN;
	for(int index = start; index <= end; index++){
		int curr = nums[start - 1] * nums[index] * nums[end + 1] + utils(nums, start, index - 1, dp) + utils(nums, index + 1, end, dp);
		cout << index << " " << curr << endl;
		max_num = max(max_num, curr); 
	}

	return dp[start][end] = max_num;
}

int maxCoins(vector<int>& nums) {
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	// return utils(nums, 1, n, dp);
	for(int start = n; start >= 1; start--){
		for(int end = 1; end <= n; end++){
			if(start > end)	continue;
			int max_num = INT_MIN;
			for(int index = start; index <= end; index++){
				int curr = nums[start - 1] * nums[index] * nums[end + 1] + dp[start][index - 1] + dp[index + 1][end];
				cout << index << " " << curr << endl;
				max_num = max(max_num, curr); 
			}
			dp[start][end] = max_num;
		}
	}
	return dp[1][n];
}

int main(){
	vector<int> nums = {1, 5};
	cout << maxCoins(nums) << endl;
}