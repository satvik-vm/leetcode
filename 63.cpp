#include <iostream>
#include <vector>

using namespace std;

int utils(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int rowIndex, int columnIndex, int rowSize, int columnSize)
{
	if (rowIndex == rowSize && columnIndex == columnSize)
		return 1 - obstacleGrid[rowIndex][columnIndex];
	if (rowIndex > rowSize)
		return 0;
	if (columnIndex > columnSize)
		return 0;
	if (obstacleGrid[rowIndex][columnIndex] == 1)
		return 0;
	if (dp[rowIndex][columnIndex] != -1)
		return dp[rowIndex][columnIndex];

	int to_return = utils(obstacleGrid, dp, rowIndex + 1, columnIndex, rowSize, columnSize) + utils(obstacleGrid, dp, rowIndex, columnIndex + 1, rowSize, columnSize);

	return dp[rowIndex][columnIndex] = to_return;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
	int rowSize = obstacleGrid.size() - 1;
	int columnSize = obstacleGrid[0].size() - 1;
	vector<vector<int>> dp(rowSize + 1, vector<int>(columnSize + 1, -1));
	return utils(obstacleGrid, dp, 0, 0, rowSize, columnSize);
}