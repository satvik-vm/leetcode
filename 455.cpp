#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int> nums, int target){
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] >= target){
                if(mid > 0){
                    if(nums[mid - 1] < target)  return mid;
                }
                else return mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {   // g is greed and s is cookies
        // sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int answer = 0;
        for(int i = 0; i < g.size(); i++){
            int greed = g[i];
            int index = binarySearch(s, greed);
            if(index != -1){
                answer++;
                s.erase(s.begin() + index);
            }
        }

        return answer;
    }
};