#include <bits/stdc++.h>


using namespace std;

class Solution {
    bool checkOverlap(vector<int> first, vector<int> second){   //first will always have initial beginning
        if(first[1] >= second[0] || first[0] >= second[1])    return true;
        return false;
    }

    static bool compare(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<vector<int>> all_sub_arrays;
        vector<int> prefix(arr.size(), 0);

        prefix[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        for(int start = 0; start < arr.size(); start++){
            if(prefix[start] == target) all_sub_arrays.push_back({0, start});
            for(int end=start+1; end < arr.size(); end++){
                if(prefix[end] - prefix[start] == target){
                    all_sub_arrays.push_back({start+1, end});
                }
            }
        }

        sort(all_sub_arrays.begin(), all_sub_arrays.end(), compare);

        int min_sum = INT_MAX;
        int n = all_sub_arrays.size();
        if(n < 2)   return -1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(!checkOverlap(all_sub_arrays[i], all_sub_arrays[j])){
                    min_sum = min(min_sum, abs(all_sub_arrays[j][1] - all_sub_arrays[j][0] + all_sub_arrays[i][1] - all_sub_arrays[i][0]) + 2);
                }
            }
        }

        return min_sum == INT_MAX ? -1 : min_sum;
    }
};