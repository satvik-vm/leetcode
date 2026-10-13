#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        priority_queue<vector<double>> pq;

        for(long long i = 0; i < val.size(); i++){
            pq.push({(double)val[i] / wt[i], val[i], wt[i]});
        }

        double max_val = 0;

        while(!pq.empty() && capacity > 0){
            vector<double> top = pq.top();
            pq.pop();
            double ratio = top[0];
            long long val = top[1];
            long long wt = top[2];
            cout << wt << endl;

            if(capacity > wt){
                capacity -= wt;
                max_val += val;
            }

            else{
                max_val += capacity * ratio;
                capacity = 0;
            }
        }

        return max_val;
    }
};