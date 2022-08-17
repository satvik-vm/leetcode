#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &nums, int l, int h){
    while(l < h){
        swap(nums[l++], nums[h--]);
    }
}

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6};
    rotate(a, 3);
    for(int i = 0; i < a.size(); i++)   cout << a[i] << " ";
    cout << endl;
}