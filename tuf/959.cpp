#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long solve(vector<int>& bt) {
		//your code goes here
		sort(bt.begin(), bt.end());

		long long total_wait_time = 0;
		long long curr_waiting_time = 0;

		for(int i = 0; i < bt.size() - 1; i++){
			curr_waiting_time += bt[i];
			total_wait_time += curr_waiting_time;
		}

		return total_wait_time / bt.size();
	}
};