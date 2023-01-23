#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<int> x, y;

    for(int i = 0;i < rows; i++){
        for(int j = 0;j < columns; j++){
            if(matrix[i][j] == 0){
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    for(int itt: x){
        for(int j = 0;j < columns; j++){
            matrix[itt][j] = 0;
        }
    }

    for(int itt: y){
        for(int i = 0;i < rows; i++){
            matrix[i][itt] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    for(auto itt1: matrix){
        for(auto itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}