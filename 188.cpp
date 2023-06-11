#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
	vector<vector<int>> curr(2, vector<int>(k + 1, 0));
	vector<vector<int>> next(2, vector<int>(k + 1, 0));

	for(int i = prices.size() - 1; i >= 0; i--){
		for(int buy = 0; buy <= 1; buy++){
			for(int cap = 1; cap <= k; cap++){
				if(buy){
					curr[buy][cap] = max(next[0][cap] - prices[i], next[1][cap]);
				}
				else{
					curr[buy][cap] = max(prices[i] + next[1][cap - 1], next[0][cap]);
				}
			}
		}
		next = curr;
	}
	return next[1][k];
}

int main(){
	int k = 2;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int answer = maxProfit(k, prices);
    cout << answer << endl;
}