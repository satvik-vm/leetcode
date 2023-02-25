#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
}

void utils(int index, vector<int> &nums, set<vector<int>> &answers, vector<int> &answer){
    if(index == nums.size()){
        answers.insert(answer);
        return;
    }

    utils(index+1, nums, answers, answer);
    answer.push_back(nums[index]);
    utils(index+1, nums, answers, answer);
    answer.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    Quicksort (nums, 0, nums.size() - 1);
    set<vector<int>> answers;
    vector<int> answer;
    utils(0, nums, answers, answer);
    vector<vector<int>> result;
    for (auto& it : answers) {
        result.push_back(it);
    }
    return result;
}

int main(){
    vector<int> nums = {4, 4, 4, 1, 4};
    vector<vector<int>> answers = subsetsWithDup(nums);
    for(int i = 0; i < answers.size(); i++){
        for(int j = 0;j < answers[i].size(); j++){
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
}