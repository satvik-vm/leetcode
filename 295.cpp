#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MedianFinder {
private:
    vector<int> nums;
public:
    MedianFinder() {
        this->nums = {INT_MIN};
    }
    
    void addNum(int num) {
		this->nums.push_back(num);
		int n = this->nums.size(), index = n - 1;
		while(index > 1 && num < nums[index / 2]){
			nums[index] = nums[index / 2];
			index /= 2;
		}
		nums[index] = num;
    }

	int delete_heap(vector<int>& nums_temp){
		int n = nums_temp.size();
		int i = 1, j = i * 2;
		int val = nums_temp[1];
		nums_temp[1] = nums_temp[n - 1];
		nums_temp.erase(nums_temp.begin() + nums_temp.size() - 1);
		while(j < n){
			if(j < n - 1 && nums_temp[j] > nums_temp[j+1]){
				j += 1;
			}
			if(nums_temp[i] > nums_temp[j]){
				int temp = nums_temp[i];
				nums_temp[i] = nums_temp[j];
				nums_temp[j] = temp;
				i = j;
				j *= 2;
			}
			else	break;
		}
		return val;
	}
    
    double findMedian() {
		vector<int> nums_temp = nums;
		vector<int> ordered;
		while(nums_temp.size()){
			ordered.push_back(delete_heap(nums_temp));
		}
		cout << "NUMS-------" << endl;
		for(auto itt: nums){
			cout << itt << " ";
		}
		cout << endl;
		cout << "ORDERED--------" << endl;
		for(auto itt: ordered){
			cout << itt << " ";
		}
		cout << endl;
		ordered.erase(ordered.begin() + 0);
		int size = ordered.size();
		cout << size << endl;
		if(size % 2 == 0){
			return (ordered[(size - 1) / 2] + ordered[size / 2]) / 2.0;
		}	else{
			return ordered[size / 2];
		}
    }
};

int main(){
	MedianFinder med;
	med.addNum(6);
	med.addNum(10);
	med.addNum(2);
	med.addNum(6);
	med.addNum(5);
	med.addNum(0);
	med.addNum(6);
	med.addNum(3);
	med.addNum(1);
	med.addNum(0);
	med.addNum(0);
	cout << med.findMedian() << endl;
}