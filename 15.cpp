#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answers;
    for(int i = 0;i < size - 2; i++){
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
            
            int low = i + 1, high = size - 1, sum = 0 - nums[i];

            while(low < high){
                if(nums[low] + nums[high] == sum){
                    answers.push_back({nums[i], nums[low], nums[high]});

                    while(low < high && nums[low] == nums[low+1])   low++;
                    while(low < high && nums[high] == nums[high+1]) high--;

                    low++;
                    high--;
                }

                else if (nums[low] + nums[high] < sum)  low++;
                else high--;
            }
        }
    }
    return answers;
}

int main()
{
    vector<int> nums = {0, 0, 0};
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