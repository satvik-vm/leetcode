#include <iostream>
#include <vector>

using namespace std;

int utils(vector<vector<int>>& grid, int row, int col_1, int col_2, int row_max, int col_max, vector<vector<vector<int>>>& dp){
	if(row == row_max){
		if(col_1 == col_2)	return grid[row][col_1];
		else return grid[row][col_1] + grid[row][col_2];
	}
	if(col_1 < 0 || col_1 > col_max || col_2 < 0 || col_2 > col_max)	return 0;
	if(dp[row][col_1][col_2] != -1)	return dp[row][col_1][col_2];

	int result = 0;
	for(int diff1 = -1; diff1 <= 1; diff1++){
		for(int diff2 = -1; diff2 <= 1; diff2++){
			if(col_1 == col_2)	result = max(result, grid[row][col_1] + utils(grid, row + 1, col_1 + diff1, col_2 + diff2, row_max, col_max, dp));
			else	result = max(result, grid[row][col_1] + grid[row][col_2] + utils(grid, row + 1, col_1 + diff1, col_2 + diff2, row_max, col_max, dp));
		}
	}
	return dp[row][col_1][col_2] = result;
}

int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
	int n = grid[0].size();
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

	return utils(grid, 0, 0, n - 1, m - 1, n - 1, dp);
}

int main(){
	vector<vector<int>> grid = {{1,0,0,0,0,0,1}, {2,0,0,0,0,3,0}, {2,0,9,0,0,0,0}, {0,3,0,5,4,0,0}, {1,0,2,3,0,0,6}};
	cout << cherryPickup(grid) << endl;
}