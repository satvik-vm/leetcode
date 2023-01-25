#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();

    for(int i = 0;i < size; i++){
        for(int j = i+1;j < size; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    for(auto itt1: matrix){
        for(int itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}