#include <iostream>
#include <chrono>
#include <cstring>

using namespace std;

int uniquePaths(int m, int n) {
    int arr[n];
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    for(int i = 0;i < m;i++){
        for(int j = 1;j < n;j++){
            arr[j] += arr[j-1];
        }
    }
    return arr[n-1];
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    int m = 3, n = 2;
    time_start = chrono::high_resolution_clock::now();
    int ans = uniquePaths(m, n);
    time_end = chrono::high_resolution_clock::now();
    cout << ans << endl;
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << time_diff.count() << " microseconds" << endl;
}