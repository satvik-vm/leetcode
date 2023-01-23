#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    vector<vector<int>> answer_dp;
    unordered_map<int, vector<vector<int>>> map;
    answer[0] = {1};
    if(numRows == 1){
        map[1] = answer;
        return answer;
    }
    if(numRows == 2){
        answer[1] = {1, 1};
        map[2] = answer;
        return answer;
    }
    if(map.find(numRows-1) != map.end()){
        answer_dp = map[numRows-1];
    }
    else    answer_dp = generate(numRows-1);
    for(int i = 0;i < answer_dp.size();i++){
        answer[i] = answer_dp[i];
    }
    for(int i = 0;i <= numRows-2; i++){
        answer[numRows-1].push_back(answer[numRows-2][i-1] + answer[numRows-2][i]);
    }
    answer[numRows-1].push_back(1);
    map[numRows] = answer;
    return answer;
}

int main(){
    int numRows = 10;
    vector<vector<int>> answer = generate(numRows);
    for(auto itt1: answer){
        for(auto itt2: itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}
