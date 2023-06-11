#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int utils(vector<int>& prices, int index, bool buy, int count, vector<vector<vector<int>>>& dp){
	if(count == 2 || index == prices.size())	return 0;
	if(dp[index][buy][count] != -1)	return dp[index][buy][count];

	if(buy){
		return dp[index][buy][count] = max(utils(prices, index + 1, false, count, dp) - prices[index], utils(prices, index + 1, true, count, dp));
	}
	else{
		return dp[index][buy][count] = max(prices[index] + utils(prices, index +  1, true, count + 1, dp), utils(prices, index + 1, false, count, dp));
	}
}

int maxProfit(vector<int>& prices) {
    // int buy1 = INT_MAX, buy2 = INT_MAX, sell1 = INT_MIN, sell2 = INT_MIN;
    // for(int i = 0; i < prices.size(); i++){
    //     buy1 = min(buy1, prices[i]);
    //     sell1 = max(sell1, prices[i] - buy1);
    //     buy2 = min(buy2, prices[i] - sell1);
    //     sell2 = max(sell2, prices[i] - buy2);
    // }
    // return sell2;
	vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
	return utils(prices, 0, 1, 0, dp);

}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int answer = maxProfit(prices);
    cout << answer << endl;
}