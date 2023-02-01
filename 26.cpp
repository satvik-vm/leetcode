#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    vector<int> answer;
    if(nums.size() == 0 || nums.size() == 1)    return 1;
    int i = 0, size = nums.size();
    while(i != size){
        while(nums[i+1] == nums[i]) i++;
        answer.push_back(nums[i]);
        i++;
    }
    for(int i = 0;i < answer.size(); i++){
        nums[i] = answer[i];
    }
    return answer.size();
}

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<int> nums = {1, 1};

    time_start = chrono::high_resolution_clock::now();
    int answer = removeDuplicates(nums);
    time_end = chrono::high_resolution_clock::now();

    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);

    cout << "size: " << answer << endl;
    for(int i = 0; i < answer; i++){
        cout << nums[i] << " ";
    }
    cout << endl << "Done [" << time_diff.count() << " microseconds]" << endl;
}