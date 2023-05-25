#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int column, char ch){
	for(int i = 0; i < 9; i++){
		if(board[row][i] == ch)	return false;

		if(board[i][column] == ch)	return false;

		if(board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == ch)	return false;
	}
	return true;
}

bool utils(vector<vector<char>>& board){
	for(int row = 0; row < board.size(); row++){
		for(int column = 0; column < board[0].size(); column++){
			if(board[row][column] == '.'){
				for(char ch = '1'; ch <= '9'; ch++){
					if(isSafe(board, row, column, ch)){
						board[row][column] = ch;
						if(utils(board))	return true;
						else	board[row][column] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
    utils(board);
}

int main(){
	vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	solveSudoku(board);
	for(auto itt1: board){
		for(auto itt2: itt1){
			cout << itt2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}

