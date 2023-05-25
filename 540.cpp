#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
	// if(nums.size() == 0)    return NULL;
    if(nums.size() == 1)    return nums[0];
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid % 2 == 0){
            if(nums[mid] == nums[mid+1])    low = mid + 1;
			else if (nums[mid-1] == nums[mid])	high = mid - 1;
			else{
				cout << mid << endl;
				return nums[mid];
			}
        } else{
			if(nums[mid] == nums[mid+1])	high = mid - 1;
			else if (nums[mid-1] == nums[mid]) low = mid + 1;
			else{
				cout << mid << endl;
				return nums[mid];
			}
		}
    }
}

int main(){
	vector<int> nums = {1,2,2,3,3};
	cout << singleNonDuplicate(nums) << endl;
}

