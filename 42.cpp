#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int trap(vector<int>& height) {
    if(height.size() == 0 || height.size() == 1)    return 0;
    int answer = 0;
    int size = height.size();
    int prefix[size], suffix[size];
    prefix[0] = height[0];
    suffix[size - 1] = height[size - 1];
    for(int i = 1;i < size; i++){
        prefix[i] = max(prefix[i-1], height[i]);
    }
    for(int i = size - 2;i >= 0; i--){
        suffix[i] = max(suffix[i+1], height[i]);
    }
    for(int i = 0;i < size; i++){
        answer += min(prefix[i], suffix[i]) - height[i];
    }
    return answer;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<int> height = {0, 2, 0};

    time_start = chrono::high_resolution_clock::now();
    int answer = trap(height);
    time_end = chrono::high_resolution_clock::now();

    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    cout << answer << endl;
    cout << "Done [" << time_diff.count() << " microseconds]" << endl;
}