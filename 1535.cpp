#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getWinner(vector<int>& arr, int k) {
    int wins = 0;
    int max_ele = *max_element(arr.begin(), arr.end());
    int i = 1;
    while(wins < k){
        if(arr[0] == max_ele) return arr[0];
        if(arr[i] < arr[0]) wins++;
        else{
            wins = 1;
            reverse(arr.begin(), arr.begin()+i);
            vector<int> temp = {arr.begin(), arr.begin()+i};
            arr.erase(arr.begin(), arr.begin()+i);
            arr.insert(arr.end(), temp.begin(), temp.end());
            i = 0;
        }
        i++;
    }

    return arr[0];
}

int main(){
    vector<int> arr = {3, 2, 1};
    int k = 10;
    cout << getWinner(arr, k) << endl;
    return 0;
}