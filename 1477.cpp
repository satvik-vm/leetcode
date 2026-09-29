#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSumOfLengths(const vector<int>& arr, int target) {
        const int n = arr.size();

        int sol  = n+1;
        int best = n+1;

        int l = -1; int sl = 0; // Sum for window (l, m]
        int r = -1; int sr = 0; // Sum for window (m, r]
        for (int m = 0; m < n; m++) {
            sl += arr[m];
            sr -= arr[m];

            while(sl > target)
                sl -= arr[++l];
            if (sl == target)
                best = min(best, m-l);

            while(r < n-1 && sr < target)
                sr += arr[++r];
            if (sr == target)
                sol = min(sol, best + r-m);
            else if (sr < target)
                break; // In this case r == n-1 and we cannot hope to find another sub-array.
        }

        if (sol == n+1) return -1;
        return sol;
    }
};