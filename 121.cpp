#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int min_left = prices[0], max_profit = 0;
    for(int i = 0;i < size; i++){
        min_left = min(min_left, prices[i]);
        max_profit = max(max_profit, prices[i] - min_left);
    }
    return max_profit;
}

int main(){
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
}

