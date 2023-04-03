#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> maxElement(unordered_map<int, int> map){
    vector<int> result = {-1, INT_MIN};
    for(auto it = map.begin(); it!= map.end(); it++){
        if(it->second > result[1]){
            result = {it->first, it->second};
        }
    }
    return result;
}

long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size();
    if(size == 0)   return 0;
    int total = 0;
    long long answer = 0;
    unordered_map<int, int> freq;

    for(int i = 0;i < size; i++){
        if(nums1[i] == nums2[i]){
            freq[nums1[i]]++;
            total++;
            answer += i;
        }
    }

    vector<int> most = maxElement(freq);

    long long twice = 2 * most[1];

    for(int i = 0; i < size && twice  > total; ++i){
        if (nums1[i] != nums2[i] && most[0] != nums1[i] && most[0] != nums2[i]) {
            ++total;
            answer += i;
        }
    }

    if(2 * most[1] > total){
        return -1;
    }

    return answer;
}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {2,1};
    cout << minimumTotalCost(nums1, nums2) << endl;
    return 0;
}