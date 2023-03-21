#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int reductionOperations(vector<int>& nums) {
    if(nums.size() <= 1)    return 0;

    sort(nums.begin(), nums.end());

    int coff = 0, freq = 1, answer = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == nums[i+1]){
            freq++;
        }
        else{
            answer += coff * freq;
            freq = 1;
            coff++;
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {5};
    cout << reductionOperations(nums) << endl;
}