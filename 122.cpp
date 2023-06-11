#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp){
	if(index == prices.size())	return 0;
	if(dp[index][buy] != -1)	return dp[index][buy];

	if(buy){
		return dp[index][buy] = max(utils(prices, index + 1, false, dp) - prices[index], utils(prices, index + 1, true, dp));
	}
	else{
		return dp[index][buy] = max(prices[index] + utils(prices, index +  1, true, dp), utils(prices, index + 1, false, dp));
	}
}

int maxProfit(vector<int>& prices) {
	// vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    // return utils(prices, 0, 1, dp);
	// dp[prices.size()][0] = 0;
	// dp[prices.size()][1] = 0;

	vector<int> curr(2, 0), next(2, 0);

	for(int i = prices.size() - 1; i >= 0; i--){
		// dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
		// dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
		curr[1] = max(next[0] - prices[i], next[1]);
		curr[0] = max(prices[i] + next[1], next[0]);
		next = curr;
	}
	
	return curr[1];
}

int main(){
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices) << endl;
}