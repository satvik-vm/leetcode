#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
private:
	vector<vector<int>> matrixRowSum;

public:
	NumMatrix(vector<vector<int>> &matrix)
	{
		matrixRowSum.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			matrixRowSum[i][0] = matrix[i][0];
			for (int j = 1; j < matrix[0].size(); j++)
			{
				matrixRowSum[i][j] = matrixRowSum[i][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		int sum = 0;
		for (int i = row1; i <= row2; i++)
		{
			if (col1 >= 1)
			{
				sum += (matrixRowSum[i][col2] - matrixRowSum[i][col1 - 1]);
			}
			else
				sum += matrixRowSum[i][col2];
		}
		return sum;
	}
};