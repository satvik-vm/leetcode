#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool util(vector<int> row, int start, int end, int target){
    int size = row.size();
    if(start == end){
        return row[start] == target;
    }
    else{
        if(target > row[(start + end) / 2]) return util(row, (start + end) / 2 + 1, end, target);
        else    return util(row, start, (start + end) / 2, target);
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0;
    int rows = matrix.size(), columns = matrix[0].size();
    while(i < rows && target > matrix[i][columns-1]){
        i++;
    }
    if(i == rows)    return false;
    if(target < matrix[i][0]){
        return false;
    }
    else{
        return util(matrix[i], 0, columns - 1, target);
    }
}

int main(){
    vector<vector<int>> matrix = {{1}};
    int target = 2;
    cout << searchMatrix(matrix, target) << endl;
}