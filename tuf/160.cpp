#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	static bool comp(vector<int> a, vector<int> b){
		return a[2] > b[2];
	}

	vector<int> JobScheduling(vector<vector<int>>& Jobs) {
		//your code goes here
		sort(Jobs.begin(), Jobs.end(), comp);
		int max_time = 0;
		for(int i = 0; i < Jobs.size(); i++){
			max_time = max(max_time, Jobs[i][1]);
		}

		vector<bool> used(max_time, false);
		int max_profit = 0, total_jobs = 0;

		for(int i = 0; i < Jobs.size(); i++){
			int deadline = Jobs[i][1];
			int profit = Jobs[i][2];

			for(int j = deadline - 1; j >= 0; j--){
				if(!used[j]){
					max_profit += profit;
					total_jobs++;
					used[j] = true;
					break;
				}
			}
		}

		return {total_jobs, max_profit};
	}
};