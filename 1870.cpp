#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPossible(vector<int> &dist, int speed, double hour)
{
	double ans = 0;
	for (int i = 0; i < dist.size(); i++)
	{
		double d = dist[i] * 1.0 / speed;
		if (i != dist.size() - 1)
			ans += ceil(d);
		else
			ans += d;
		if (ans > hour)
			return false;
	}
	if (ans <= hour)
		return true;
	return false;
}

int minSpeedOnTime(vector<int> &dist, double hour)
{
	int low = 1, high = 1e9;
	int answer = -1;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (isPossible(dist, mid, hour))
		{
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return answer;
}