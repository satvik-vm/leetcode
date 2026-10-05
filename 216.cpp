#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> curr;
        utils(k, n, 0, 0, answer, curr);
        return answer;
    }

    void utils(int k, int n, int sum, int index, vector<vector<int>>& answer, vector<int>& curr){   //index from 1 to 9
        if(k == 0 && n == sum)    {
            answer.push_back(curr);
            return;
        }
        if(k == 0)  return;

        for(int i = index + 1; i < 10; i++){
            curr.push_back(i);
            utils(k - 1, n, sum + curr[curr.size() - 1], i, answer, curr);
            curr.pop_back();
        }
    }
};

int main(){
	Solution sol;
	int k = 3, n = 7;
	vector<vector<int>> answer = sol.combinationSum3(k, n);
	for(int i = 0; i < answer.size(); i++){
		for(int j = 0; j < answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
}