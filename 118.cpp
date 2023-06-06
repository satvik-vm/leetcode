#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> result(numRows);
	for(int i = 0; i < numRows; i++){
		result[i].resize(i + 1, 1);
		cout << 1 << endl;
		for(int j = 0; j < i - 1; j++){
			result[i][j+1] = result[i - 1][j] + result[i - 1][j + 1];
		}
	}
	return result;
}

int main(){
    int numRows = 5;
    vector<vector<int>> answer = generate(numRows);
    for(auto itt1: answer){
        for(auto itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}
