#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
	priority_queue<vector<int>, vector<vector<int>>> pq;
	int size1 = nums1.size(), size2 = nums2.size();
	int min1 = min(size1, k), min2 = min(size2, k);
	for (int i = 0; i < min1; i++)
	{
		for (int j = 0; j < min2; j++)
		{
			int sum = nums1[i] + nums2[j];
			if (pq.size() < k)
			{
				pq.push({sum, nums1[i], nums2[j]});
			}
			else if (pq.top()[0] > sum)
			{
				pq.pop();
				pq.push({sum, nums1[i], nums2[j]});
			}
			else if (pq.top()[0] < sum)
			{
				break;
			}
		}
	}

	vector<vector<int>> answer;

	while (k-- && !pq.empty())
	{
		vector<int> curr = pq.top();
		pq.pop();
		answer.push_back({curr[1], curr[2]});
	}

	return answer;
}

int main()
{
	vector<int> nums1 = {1, 1, 2};
	vector<int> nums2 = {1, 2, 3};
	int k = 10;
	vector<vector<int>> answer = kSmallestPairs(nums1, nums2, k);

	for (vector<int> itt1 : answer)
	{
		for (int itt2 : itt1)
		{
			cout << itt2 << " ";
		}
		cout << endl;
	}
}