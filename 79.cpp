#include <iostream>
#include <vector>

using namespace std;

bool utils(vector<vector<char>> &board, string word, int rowIndex, int columnIndex, int wordIndex, vector<vector<bool>> &isVisited)
{
	if (wordIndex == word.size())
		return true;
	if (rowIndex > board.size() - 1 || columnIndex > board[0].size() - 1 || rowIndex < 0 || columnIndex < 0)
		return false;
	if (board[rowIndex][columnIndex] != word[wordIndex])
		return false;
	if (isVisited[rowIndex][columnIndex])
		return false;
	isVisited[rowIndex][columnIndex] = true;
	bool right = utils(board, word, rowIndex, columnIndex + 1, wordIndex + 1, isVisited);
	bool left = utils(board, word, rowIndex, columnIndex - 1, wordIndex + 1, isVisited);
	bool up = utils(board, word, rowIndex - 1, columnIndex, wordIndex + 1, isVisited);
	bool down = utils(board, word, rowIndex + 1, columnIndex, wordIndex + 1, isVisited);
	// cout << rowIndex << " " << columnIndex << " " << right << " " << left << " " << up << " " << down << endl;
	if (!(right | left | up | down))
		isVisited[rowIndex][columnIndex] = false;
	return right | left | up | down;
}
bool exist(vector<vector<char>> &board, string word)
{
	for (int rowIndex = 0; rowIndex < board.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < board[0].size(); columnIndex++)
		{
			vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
			if (utils(board, word, rowIndex, columnIndex, 0, isVisited))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "ABCESEEEFS";
	cout << exist(board, word) << endl;
}