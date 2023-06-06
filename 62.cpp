#include <iostream>
#include <chrono>
#include <cstring>
#include <vector>

using namespace std;

int utils(int m, int n, int row, int column, vector<vector<int>> dp){
	if(dp[m][n] != -1)	return dp[m][n];
	if(row == m && column == n)	return 1;
	if(row > m || column > n)	return 0;
	int column_increase = utils(m, n, row, column + 1, dp);
	int row_increase = utils(m, n, row + 1, column, dp);
	return dp[m][n] = column_increase + row_increase;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return utils(m - 1, n - 1, 0, 0, dp);
}

int main(){
	int m = 3, n = 7;
	cout << uniquePaths(m, n) << endl;
}