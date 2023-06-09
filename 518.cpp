#include <iostream>
#include <vector>

using namespace std;

int utils(vector<int>& coins, int amount, int index, vector<vector<int>> dp){
	if(amount == 0)	return 1;
	if(index == coins.size() - 1){
		if(amount % coins[index])	return amount / coins[index];
		else return 0;
	}
	if(dp[index][amount] != -1)	return dp[index][amount];

	int not_pick = utils(coins, amount, index + 1, dp);
	int pick = 0;
	if(coins[index] <= amount)	pick = utils(coins, amount - coins[index], index, dp);

	return dp[index][amount] = not_pick + pick;
}

int change(int amount, vector<int>& coins) {
	vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return utils(coins, amount, 0, dp);
}

int main(){
	vector<int> coins = {5};
	int amount = 10;
	cout << change(amount, coins) << endl;
}