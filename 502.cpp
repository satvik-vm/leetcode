#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
	int size = profits.size();
	vector<pair<int, int>> list;
	for (int i = 0; i < size; i++)
	{
		list.push_back({capital[i], profits[i]});
	}
	sort(list.begin(), list.end());
	priority_queue<int> pq;
	int index = 0;
	while (k--)
	{
		while (index < size && list[index].first <= w)
		{
			pq.push(list[index].second);
			index++;
		}
		if (pq.empty())
			break;
		w += pq.top();
		pq.pop();
	}
	return w;
}

int main(){
	vector<int> profits = {1,2,3};
	vector<int> capital = {1,1,2};
	int w = 2;
	int k = 1;
	cout << findMaximizedCapital(k, w, profits, capital) << endl;
}