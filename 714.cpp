#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int>& prices, int fee, int index, bool buy, vector<vector<int>> dp){
	if(index == prices.size())	return 0;
	if(dp[index][buy] != -1)	return dp[index][buy];

	if(buy){
		return max(-prices[index] + utils(prices, fee, index + 1, false, dp), utils(prices, fee, index + 1, true, dp));
	}
	else{
		return max(prices[index] + utils(prices, fee, index + 1, true, dp) - fee, utils(prices, fee, index + 1, false, dp));
	}
}

int maxProfit(vector<int>& prices, int fee) {
	// vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    // return utils(prices, fee, 0, 1, dp);
	// for(int index = prices.size() - 1; index >= 0; index--){
	// 	for(int buy = 0; buy <= 1; buy++){
	// 		if(buy){
	// 			dp[index][1] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
	// 		}
	// 		else{
	// 			dp[index][0] = max(prices[index] + dp[index + 1][1] - fee, dp[index + 1][0]);
	// 		}
	// 	}
	// }
	// return dp[0][1];
	vector<int> curr(2, 0), next(2, 0);
	for(int index = prices.size() - 1; index >= 0; index--){
		curr[1] = max(-prices[index] + next[0], next[1]);
		curr[0] = max(prices[index] + next[1] - fee, next[0]);
		next = curr;
	}
	return curr[1];
}

int main(){
	vector<int> prices = {1,3,7,5,10,3};
	int fee = 3;
	cout << maxProfit(prices, fee) << endl;
}