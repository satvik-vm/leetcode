#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
	int m = board.size();
	int n = board[0].size();
	map<pair<int, int>, int> mpOne;
	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int delta_x = -1; delta_x < 2; delta_x++)
			{
				int x_new = x + delta_x;
				if (x_new < m && x_new >= 0)
				{
					for (int delta_y = -1; delta_y < 2; delta_y++)
					{
						if (delta_x == 0 && delta_y == 0)
							continue;
						int y_new = y + delta_y;
						if (y_new < n && y_new >= 0)
						{
							if (board[x_new][y_new])
								mpOne[{x, y}]++;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mpOne[{i, j}] < 2)
				board[i][j] = 0;
			else if (board[i][j] == 1 && (mpOne[{i, j}] == 2 || mpOne[{i, j}] == 3))
				continue;
			else if (board[i][j] == 1 && mpOne[{i, j}] > 3)
				board[i][j] = 0;
			else if (board[i][j] == 0 && mpOne[{i, j}] == 3)
				board[i][j] = 1;
		}
	}
}

int main()
{
	vector<vector<int>> board = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
	gameOfLife(board);
	cout << "------BOARD-------" << endl;
	for (auto itt : board)
	{
		for (auto itt1 : itt)
			cout << itt1 << " ";
		cout << endl;
	}
}