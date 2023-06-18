#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int utils(int index, vector<int> arr, int k, vector<int>& dp){
	int n = arr.size();
	if(index == n)	return 0;
	if(dp[index] != -1)	return dp[index];

	int max_ans = INT_MIN, max_num = INT_MIN, len = 0;
	for(int i = index; i < min(n, index + k); i++){
		// cout << "i: " << i << " index: " << index << endl;
		len++;
		max_num = max(max_num, arr[i]);
		int sum = max_num * len + utils(i + 1, arr, k, dp);
		max_ans = max(sum, max_ans);
	}
	return dp[index] = max_ans;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	vector<int> dp(n + 1, 0);
    // return utils(0, arr, k, dp);
	for(int index = n - 1; index >= 0; index--){
		int max_ans = INT_MIN, max_num = INT_MIN, len = 0;
		for(int i = index; i < min(n, index + k); i++){
			len++;
			max_num = max(max_num, arr[i]);
			int sum = max_num * len + dp[i + 1];
			max_ans = max(sum, max_ans);
		}
		dp[index] = max_ans;
	}
	return dp[0];
}

int main(){
	vector<int> arr = {1,15,7,9,2,5,10};
	int k = 3;
	cout << maxSumAfterPartitioning(arr, k) << endl;
}

