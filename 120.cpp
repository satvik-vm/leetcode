#include <iostream>
#include <vector>

using namespace std;

int utils(vector<vector<int>> &triangle, int rowIndex, int columnIndex, int rowSize, vector<vector<int>> &dp)
{
	if (rowIndex == rowSize)
		return triangle[rowIndex][columnIndex];
	if (dp[rowIndex][columnIndex] != -1)
		return dp[rowIndex][columnIndex];
	int to_return = triangle[rowIndex][columnIndex] + min(utils(triangle, rowIndex + 1, columnIndex, rowSize, dp), utils(triangle, rowIndex + 1, columnIndex + 1, rowSize, dp));
	return dp[rowIndex][columnIndex] = to_return;
}
int minimumTotal(vector<vector<int>> &triangle)
{
	int rowSize = triangle.size() - 1;
	vector<vector<int>> dp(rowSize);
	for (int i = 0; i < rowSize; i++)
	{
		dp[i].resize(triangle[i].size(), -1);
	}
	return utils(triangle, 0, 0, rowSize, dp);
}