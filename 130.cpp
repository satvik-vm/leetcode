#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> bfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int column, bool& safe)
{
	visited[row][column] = true;
	queue<pair<int, int>> q;
	q.push({row, column});
	int n = board.size(), m = board[0].size();
	int next_row, next_column;
	vector<vector<int>> traversed;
	while (!q.empty())
	{
		int curr_row = q.front().first, curr_column = q.front().second;
		if(!safe && (curr_row == 0 || curr_row == n - 1 || curr_column == 0 || curr_column == m - 1))	safe = true;
		traversed.push_back({curr_row, curr_column});
		q.pop();
		next_row = curr_row - 1;
		next_column = curr_column;
		if (next_row >= 0 && board[next_row][next_column] == 'O' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row + 1;
		next_column = curr_column;
		if (next_row < n && board[next_row][next_column] == 'O' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row;
		next_column = curr_column - 1;
		if (next_column >= 0 && board[next_row][next_column] == 'O' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
		next_row = curr_row;
		next_column = curr_column + 1;
		if (next_column < m && board[next_row][next_column] == 'O' && !visited[next_row][next_column])
		{
			visited[next_row][next_column] = true;
			q.push({next_row, next_column});
		}
	}
	return traversed;
}

void solve(vector<vector<char>>& board) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    vector<vector<int>> isSafe(board.size(), vector<int>(board[0].size(), 0));
	// 0 means ocean, 1 means unsafe land, 2 means safe land
	int answer = 0;
	int n = board.size(), m = board[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && board[i][j] == 'O')
			{
				bool safe = false;
				answer++;
				vector<vector<int>> traversed = bfs(board, visited, i, j, safe);
				for(auto itt: traversed){
					if(safe){
						isSafe[itt[0]][itt[1]] = 2;
					}
					else{
						isSafe[itt[0]][itt[1]] = 1;
					}
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 'O' && isSafe[i][j] == 1)	board[i][j] = 'X';
		}
	}
	return;
}

int main(){
	// vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	vector<vector<char>> board = {{'X'}};

	solve(board);
	for(auto itt1: board){
		for(auto itt2: itt1)	cout << itt2 << " ";
		cout << endl;
	}
}