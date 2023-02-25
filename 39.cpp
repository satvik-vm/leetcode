#include <iostream>
#include <vector>

using namespace std;

void utils(int index, vector<int>& candidates, int target, vector<vector<int>>& answers, vector<int>& answer){
    if(index == candidates.size()){
        if(target == 0){
            answers.push_back(answer);
        }
        return;
    }

    if(candidates[index] <= target){
        answer.push_back(candidates[index]);
        utils(index, candidates, target-candidates[index], answers, answer);
        answer.pop_back();
    }

    utils(index+1, candidates, target, answers, answer);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> result;
    utils(0, candidates, target, results, result);
    return results;
}

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> answers = combinationSum(candidates, target);
    for(int i = 0; i < answers.size(); i++){
        for(int j = 0;j < answers[i].size(); j++){
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
}