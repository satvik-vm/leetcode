#include <iostream>
#include <vector>
#include <utility> 
#include <bits/stdc++.h>

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int size = names.size();
    vector<pair<int, int>> list(size);
    for(int i = 0;i < size;i++){
        list[i] = {heights[i], i};
    }
    sort(list.rbegin(), list.rend());
    vector<string> answer(size);
    for(int i = 0;i < size;i++){
        answer[i] = names[list[i].second];
    }
    return answer;
}

int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> answer = sortPeople(names, heights);
    for(auto itt : answer)   cout << itt << " ";
    cout << endl;
}