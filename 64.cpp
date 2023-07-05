#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int utils(vector<vector<int>> &grid, vector<vector<int>> &dp, int rowIndex, int columnIndex, int rowSize, int columnSize)
{
	// cout << rowIndex << " " << columnIndex << " ";
	// if(rowIndex <= size && columnIndex <= size)	cout << grid[rowIndex][columnIndex];
	// cout << endl;
	if (rowIndex == rowSize && columnIndex == columnSize)
		return grid[rowSize][columnSize];
	if (rowIndex > rowSize)
		return INT_MAX;
	if (columnIndex > columnSize)
		return INT_MAX;
	if (dp[rowIndex][columnIndex] != -1)
		return dp[rowIndex][columnIndex];
	int right = utils(grid, dp, rowIndex + 1, columnIndex, rowSize, columnSize);
	int down = utils(grid, dp, rowIndex, columnIndex + 1, rowSize, columnSize);
	cout << rowIndex << " " << columnIndex << " " << grid[rowIndex][columnIndex] << " " << right << " " << down << endl;
	return dp[rowIndex][columnIndex] = grid[rowIndex][columnIndex] + min(right, down);
}

int minPathSum(vector<vector<int>> &grid)
{
	int rowSize = grid.size() - 1, columnSize = grid[0].size() - 1;
	vector<vector<int>> dp(rowSize + 1, vector<int>(columnSize + 1, -1));
	return utils(grid, dp, 0, 0, rowSize, columnSize);
}

int main(){
	vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	cout << minPathSum(grid) << endl;
}