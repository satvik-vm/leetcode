#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool comp(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
	sort(intervals.begin(), intervals.end(), comp);
	int answer = 0;
	int prev = 0;
	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] < intervals[prev][1])
		{
			answer++;
		}
		else
		{
			prev = i;
		}
	}
	return answer;
}