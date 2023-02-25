#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> answer;

    int nums1_itt = 0, nums2_itt = 0;

    while(nums1_itt < m && nums2_itt < n){
        if(nums1[nums1_itt] < nums2[nums2_itt]){
            answer.push_back(nums1[nums1_itt]);
            nums1_itt++;
        }
        else{
            answer.push_back(nums2[nums2_itt]);
            nums2_itt++;
        }
    }

    while(nums1_itt < m){
        answer.push_back(nums1[nums1_itt]);
        nums1_itt++;
    }

    while(nums2_itt < n){
        answer.push_back(nums2[nums2_itt]);
        nums2_itt++;
    }

    nums1 = answer;
}

int main(){
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = nums2.size();
    merge(nums1, m, nums2, n);
    for(int itt: nums1){
        cout << itt << " ";
    }
    cout << endl;
}