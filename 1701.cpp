#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double averageWaitingTime(vector<vector<int>>& A) {
    double wait = 0, cur = 0;
    for (auto& a: A) {
        cur = max(cur, 1.0 * a[0]) + a[1];
        wait += cur - a[0];
    }
    return 1.0 * wait / A.size();
}

int main(){
    vector<vector<int>> customers = {{2, 3}, {6, 3}, {7, 5}, {11, 3}, {15, 2}, {18, 1}};
    cout << averageWaitingTime(customers) << endl;
}
