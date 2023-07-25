#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
	int low = 0;
	int high = arr.size() - 1;
	int mid = (low + high) / 2;
	while (low < high)
	{
		if (mid != 0 && mid != arr.size() - 1)
		{
			if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
				return mid;
			if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
				high = mid - 1;
			else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
				low = mid + 1;
		}
		else if (mid == 0)
		{
			if (arr[mid] < arr[mid + 1])
				low = mid + 1;
			else
				return mid;
		}
		else if (mid == arr.size() - 1)
		{
			if (arr[mid] < arr[mid - 1])
				high = mid - 1;
			else
				return mid;
		}
		mid = (low + high) / 2;
	}
	return mid;
}

int main(){
	vector<int> arr = {3,5,3,2,0};
	cout << peakIndexInMountainArray(arr) << endl;
}