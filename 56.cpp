#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), sortcol);
    vector<vector<int>> answer;
    int size = intervals.size();
    vector<int> pointer = intervals[0];
    for(int i = 1; i < size; i++){
        if(pointer[1] >= intervals[i][0]){
            pointer[1] = max(intervals[i][1], pointer[1]);
        }
        else{
            answer.push_back(pointer);
            pointer = intervals[i];
        }
    }
    answer.push_back(pointer);
    return answer;
}

int main(){
    vector<vector<int>> intervals = {{1, 4}, {0, 4}};
    vector<vector<int>> answer = merge(intervals);
    for(auto itt1: answer){
        for(auto itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}