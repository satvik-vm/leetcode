#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp){
	if(index >= prices.size())	return 0;
	// if(dp[index][buy] != -1)	return dp[index][buy];

	if(buy){
		return dp[index][buy] = max(utils(prices, index + 1, false, dp) - prices[index], utils(prices, index + 1, true, dp));
	}
	else{
		return dp[index][buy] = max(prices[index] + utils(prices, index +  2, true, dp), utils(prices, index + 1, false, dp));
	}
}

int maxProfit(vector<int>& prices) {
	vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
    // return utils(prices, 0, 1, dp);
	for(int index = prices.size() - 1; index >= 0; index--){
		for(int buy = 0; buy <= 1; buy++){
			if(buy){
				dp[index][1] = max(dp[index + 1][0] - prices[index], dp[index + 1][1]);
			}
			else{
				dp[index][0] = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
			}
		}
	}
	return dp[0][1];
}

int main(){
	vector<int> prices = {1,2,3,0,2};
	cout << maxProfit(prices) << endl;
}