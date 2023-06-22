#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int column)
{
	visited[row][column] = true;
	queue<pair<int, int>> q;
	q.push({row, column});
	int n = grid.size(), m = grid[0].size();
	int next_row, next_column;
	while (!q.empty())
	{
		int curr_row = q.front().first, curr_column = q.front().second;
		q.pop();
		next_row = curr_row - 1;
		next_column = curr_column;
		if (next_row >= 0 && grid[next_row][next_column] == '1' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row + 1;
		next_column = curr_column;
		if (next_row < n && grid[next_row][next_column] == '1' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row;
		next_column = curr_column - 1;
		if (next_column >= 0 && grid[next_row][next_column] == '1' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row;
		next_column = curr_column + 1;
		if (next_column < m && grid[next_row][next_column] == '1' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
	}
}
int numIslands(vector<vector<char>> &grid)
{
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	int answer = 0;
	int n = grid.size(), m = grid[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && grid[i][j] == '1')
			{
				answer++;
				bfs(grid, visited, i, j);
			}
		}
	}
	return answer;
}

int main()
{
	vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}};
	cout << numIslands(grid) << endl;
}