#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    if(changed.size() % 2 != 0){
        return {};
    }
    unordered_map<int, int> map;
    vector<int> result;
    sort(changed.begin(), changed.end());
    for(int i = 0; i < changed.size(); i++){
        map[changed[i]]++;
    }
    for(int i = 0; i < changed.size(); i++){
        if (map[changed[i]] > 0){
            if (map[changed[i] * 2] > 0){
                result.push_back(changed[i]);
                map[changed[i]]--;
                map[changed[i] * 2]--;
            } else {
                return {};
            }
        }
    }
    return result;
}

int main(){
    vector<int> changed = {0};
    vector<int> result = findOriginalArray(changed);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}