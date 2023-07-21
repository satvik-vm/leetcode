#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder
{
public:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	MedianFinder()
	{
	}

	void addNum(int num)
	{
		maxHeap.push(num);
		int top = maxHeap.top();
		minHeap.push(top);
		maxHeap.pop();
		if (minHeap.size() > maxHeap.size())
		{
			top = minHeap.top();
			maxHeap.push(top);
			minHeap.pop();
		}
	}

	double findMedian()
	{
		if (maxHeap.size() > minHeap.size())
			return maxHeap.top();
		return (maxHeap.top() + minHeap.top()) / 2.0;
	}
};

int main()
{
	MedianFinder *obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	cout << obj->findMedian() << endl;
	obj->addNum(3);
	cout << obj->findMedian() << endl;
}