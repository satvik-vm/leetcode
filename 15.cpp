#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size; i++){
        int j = i + 1;
        int k = size - 1;
        while (j < size && j < k){
            if (nums[j] + nums[k] + nums[i] == 0){
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j != size - 1 && nums[j] == nums[j + 1])
                    j++;
                while (k != 0 && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if (nums[j] + nums[k] > -nums[i]){
                while (k != 0 && nums[k] == nums[k - 1])
                    k--;
                k--;
            }
            else{
                while (j != size && nums[j] == nums[j + 1])
                    j++;
                j++;
            }
        }
        while (i != size - 1 && nums[i] == nums[i + 1])
            i++;
    }
    for (auto itt : ans)
        sort(itt.begin(), itt.end());
    return ans;
}

int main()
{
    vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto itt : ans)
    {
        for (auto itt2 : itt)
        {
            cout << itt2 << " ";
        }
        cout << endl;
    }
}