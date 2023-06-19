#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void utils(vector<int> candidate, int target, int index, vector<vector<int>>& result, vector<int>& curr_result){
	cout << index << " " << target << endl;
	if(index == candidate.size()){
		if(target == 0){
			result.push_back(curr_result);
		}
		return;
	}

	utils(candidate, target, index + 1, result, curr_result);
	if(target >= candidate[index]){
		curr_result.push_back(candidate[index]);
		utils(candidate, target - candidate[index], index + 1, result, curr_result);
		curr_result.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> curr_result;
	utils(candidates, target, 0, result, curr_result);
	set<vector<int>> set;
	for(int i = 0; i < result.size(); i++)	set.insert(result[i]);
	result.assign(set.begin(), set.end());
	return result;
}

int main(){
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;
	vector<vector<int>> result = combinationSum2(candidates, target);
	for(auto itt1: result){
		for(int itt2: itt1)	cout << itt2 << " ";
		cout << endl;
	}
}