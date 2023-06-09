#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int utils(vector<int>& coins, int amount, int index, vector<vector<int>> dp){
	// cout << index << " " << amount << endl;
	if(index == coins.size() - 1){
		if(amount % coins[coins.size() - 1] == 0)	return amount / coins[coins.size() - 1];
		else return 1e9;
	}
	if(dp[index][amount] != -1)	return dp[index][amount];

	int not_take = utils(coins, amount, index + 1, dp);
	int take = INT_MAX;
	if(coins[index] <= amount)	take = 1 + utils(coins, amount - coins[index], index, dp);
	// cout << "take: " << take << " not take: " << not_take << endl;

	return dp[index][amount] = min(take, not_take);
}

int coinChange(vector<int>& coins, int amount) {
	vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int ans = utils(coins, amount, 0, dp);
    if(ans >= 1e8)  return -1;
    return ans;
}

int main(){
	vector<int> coins = {1, 2, 5};
	int amount = 11;

	cout << coinChange(coins, amount) << endl;
}