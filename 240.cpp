#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = matrix.size() - 1;
    int j = 0;
    while (i >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] > target) {
            i --;
        }
        else if (matrix[i][j] < target) {
            j ++;
        }
        else {
            return true;
        }
    }
    return false;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;
    vector<vector<int>> vec1 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    for(auto target : vec1){
        for(auto targetin : target){
            time_start = chrono::high_resolution_clock::now();
            bool ans = searchMatrix(vec1, targetin);
            time_end = chrono::high_resolution_clock::now();
            cout << targetin << " " << ans << endl;
            time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
            cout << "Done [" << time_diff.count() << " microseconds]" << endl << endl;
        }
    }
}