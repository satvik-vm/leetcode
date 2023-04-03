#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> simplifiedFractions(int n) {
    vector<string> result;
    for(int i = 2;i <= n; i++){
        for(int j = 1;j <= i; j++){
            if(__gcd(i, j) == 1){
                result.push_back(to_string(j) + "/" + to_string(i));
            }
        }
    }
    return result;
}

int main(){
    int n = 6;
    vector<string> answer = simplifiedFractions(n);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}