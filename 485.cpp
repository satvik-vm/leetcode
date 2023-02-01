#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int answer = 0, current = 0;
    int size = nums.size();
    for(int i = 0;i < size;i++){
        if(nums[i] == 1){
            current++;
            if(answer < current){
                answer = current;
            }
        }
        else{
            current = 0;
        }
    }
    return answer;
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<int> nums = {1,1,0,1,1,1};

    time_start = chrono::high_resolution_clock::now();
    int answer = findMaxConsecutiveOnes(nums);
    time_end = chrono::high_resolution_clock::now();

    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    cout << answer << endl;
    cout << "Done [" << time_diff.count() << " microseconds]" << endl;
}