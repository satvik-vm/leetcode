#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class NumArray {
private:
    vector<int> bstree, arr;
    int n;
    int generateTree(int i, int j, int indx, vector<int> nums, vector<int> bstree){
        if(i > j) return 0;
        if(i == j)  return bstree[indx] = nums[i];
        // cout << 1 << endl;
        int mid = (i + j) / 2;
        return bstree[indx] = generateTree(i, mid, 2*indx + 1, nums, bstree) + generateTree(mid + 1, j, 2*indx + 2, nums, bstree);
    }

    void makeUpdate(int i, int j, int indx, int diff, vector<int> bstree){
        if(i > indx || j < indx) return;
        bstree[indx] += diff;
        if(i < j){
            int mid = (i + j) / 2;
            makeUpdate(i, mid, indx*2 + 1, diff, bstree);
            makeUpdate(mid + 1, j, indx*2 + 2, diff, bstree);
        }
    }

    int getSum(int i, int j, int left, int right, int indx, vector<int> bstree){
        if(i > j)   return 0;
        if(j < left || i > right)   return 0;
        if(i >= left && j <= right) return bstree[indx];
        int mid = (i + j) / 2;
        return getSum(i, mid, left, right, indx*2 + 1, bstree) + getSum(mid + 1, j,left, right, indx*2 + 2, bstree);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size() - 1;
        bstree = vector<int>(nums.size() * 4);
        arr = nums;
        generateTree(0, n, 0, nums, bstree);
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        makeUpdate(0, n, index, diff, bstree);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, n, left, right, 0, bstree);
    }
};

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    vector<int> nums = {1, 3, 5};
    time_start = chrono::high_resolution_clock::now();
    NumArray *obj = new NumArray(nums);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << "created in " << time_diff.count() << " microseconds" << endl;

    time_start = chrono::high_resolution_clock::now();
    int ans = obj->sumRange(0, 2);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << ans << endl << "sum in " << time_diff.count() << " microseconds" << endl;

    time_start = chrono::high_resolution_clock::now();
    obj->update(1, 2);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << "updated in " << time_diff.count() << " microseconds" << endl;

    time_start = chrono::high_resolution_clock::now();
    ans = obj->sumRange(0, 2);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << ans << endl << "sum in " << time_diff.count() << " microseconds" << endl;
}