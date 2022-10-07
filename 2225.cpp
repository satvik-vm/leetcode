#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> map;

    for(int i = 0;i < matches.size();i++){
        map[matches[i][0]] = 0;
        map[matches[i][1]] = 0;
    }
    for(int i = 0;i < matches.size();i++){
        map[matches[i][1]]++;
    }

    vector<vector<int>> answer;
    vector<int> all_win, one_lose;
    for(auto itt : map){
        if(itt.second == 0){
            all_win.push_back(itt.first);
        } 
        else if(itt.second == 1)    one_lose.push_back(itt.first);
    }

    answer.push_back(all_win);
    answer.push_back(one_lose);

    return answer;
}

int main(){
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}}, answer;
    answer = findWinners(matches);
    for(auto itt1 : answer){
        for(auto itt2 : itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}