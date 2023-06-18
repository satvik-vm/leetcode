#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int utils(vector<int> arr, int start, int end)
{
	if (start > end)
		return 0;
	int min_num = INT_MAX;
	for (int index = start; index <= end; index++)
	{
		int cost = arr[end + 1] - arr[start - 1] + utils(arr, start, index - 1) + utils(arr, index + 1, end);
		min_num = min(min_num, cost);
	}
	return min_num;
}

int minCost(int n, vector<int> &cuts)
{
	cuts.push_back(n);
	cuts.insert(cuts.begin(), 0);
	sort(cuts.begin(), cuts.end());
	return utils(cuts, 1, cuts.size());
}

int main()
{
	vector<int> cuts = {5, 6, 1, 4, 2};
	int n = 9;
	cout << minCost(n, cuts) << endl;
}