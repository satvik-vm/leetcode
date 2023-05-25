#include <iostream>
#include <vector>

using namespace std;

bool isempty(vector<string> result, int column, int row){
	int n = result.size();

	for(int i = 0; i <= column; i++){
		if(result[row][i] == 'Q')	return false;
	}

	int column_1 = column, row_1 = row;

	while(column_1 >= 0 && row_1 >= 0){
		if(result[row_1][column_1] == 'Q')	return false;
		column_1--;
		row_1--;
	}

	column_1 = column, row_1 = row;	

	while(row_1 < n && column_1 >= 0){
		if(result[row_1][column_1] == 'Q')	return false;
		column_1--;
		row_1++;
	}

	return true;

}

void utils(vector<vector<string>> &result, vector<string> &curr_result, int column, int n){
	if(column == n){
		result.push_back(curr_result);
		return;
	}
	for(int i = 0; i < n; i++){
		if(isempty(curr_result, column, i)){
			curr_result[i][column] = 'Q';
			utils(result, curr_result, column+1, n);
			curr_result[i][column] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n){
	vector<vector<string>> result;
	vector<string> curr_result(n);
	string str(n, '.');

	for(int i = 0; i < n; i++){
		curr_result[i] = str;
	}

	utils(result, curr_result, 0, n);

	return result;
}

int main(){
	int n = 9;
	vector<vector<string>> answer = solveNQueens(n);
	for(auto itt1: answer){
		for(auto itt2: itt1){
			for(auto itt3: itt2){
				cout << itt3 << " ";
			}
			cout << endl;
		}
		cout << endl << "---------------------" << endl;
	}
}