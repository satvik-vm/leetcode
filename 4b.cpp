#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
    if(a > b)   return a;
    else return b;
}

int min(int a, int b){
    if(a < b)   return a;
    else return b;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if(m > n)   return findMedianSortedArrays(nums2, nums1);
    if(m == 0){
        if(n%2 == 0)   return (nums2[n/2-1] + nums2[n/2]) / 2.0;
        return nums2[n/2];
    }
    int start = 0;
    int end = m;
    int realmid = (m + n + 1) / 2;
    while(start <= end){
        int middle = (start + end) / 2;
        int leftAsize = middle;
        int leftBsize = realmid - leftAsize;
        cout << leftAsize << " " << leftBsize << " " << endl;
        int leftA = (leftAsize > 0) ? nums1[leftAsize - 1] : INT32_MIN;
        int leftB = (leftBsize > 0) ? nums2[leftBsize - 1] : INT32_MIN;
        int rightA = (m > leftAsize) ? nums1[leftAsize] : INT32_MAX;
        int rightB = (n > leftBsize) ? nums2[leftBsize] : INT32_MAX;
        cout << leftA << " " << rightA << " " << leftB << " " << rightB << endl;
        if((leftA <= rightB) && (leftB <= rightA)){
            if((m + n) % 2 == 0){
                cout << max(leftA, leftB) << " " << min(rightA, rightB) << endl;
                cout << (max(leftA, leftB) + min(rightA, rightB)) / 2.0 << endl;
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            return max(leftA, leftB);
        }
        else if(leftA > rightB) end = middle - 1;
        else    start = middle + 1;
    }
    return 0.0;
}

int main(){
    vector<int> a = {};
    vector<int> b = {100000, 100001};
    double ans = findMedianSortedArrays(a, b);
    double b1 = 100000.5000;
    cout << ans << " " << b1 << endl;
}