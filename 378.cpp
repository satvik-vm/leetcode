#include <iostream>
#include <set>
#include <vector>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    multiset<int> multi;

    for(auto itt : matrix){
        for(auto itt2 : itt){
            multi.insert(itt2);
        }
    }

    int ans;
    for(auto itt : multi){
        if(k == 0)  break;
        ans = itt;
        k--;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int ans = kthSmallest(matrix, k);
    cout << ans << endl;
}