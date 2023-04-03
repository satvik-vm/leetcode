#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, set<int>> map;
    unordered_map<int, int> freq;
    for(int i = 0; i < logs.size(); i++){
        map[logs[i][0]].insert(logs[i][1]);
    }
    for(auto itt: map){
        freq[itt.first] = itt.second.size();
    }
    vector<int> answer(k, 0);
    for(auto itt: freq){
        if(itt.second <= k)  answer[itt.second-1]++;
    }
    return answer;
}

int main(){
    vector<vector<int>> logs = {{283268890,14532}, {283268891,14530}, {283268889,14530}, {283268892,14530}, {283268890,14531}};
    int k = 2;
    vector<int> answer = findingUsersActiveMinutes(logs, k);
    for(int i = 0;i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}