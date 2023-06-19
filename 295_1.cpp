#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder
{
private:
	vector<int> pr;
	// queue<int> dump;
public:
	MedianFinder()
	{
	}

	void addNum(int num)
	{
		this->pr.push_back(num);
		sort(pr.begin(), pr.end());
	}

	double findMedian()
	{
		int n = this->pr.size();
		if (n % 2 != 0)
			return pr[n / 2];
		else
		{
			cout << pr[n / 2] << " " << pr[(n - 1) / 2] << endl;
			return (double)(pr[n / 2] + pr[(n - 1) / 2]) / 2;
		}
	}
};

int main()
{
	MedianFinder *obj = new MedianFinder();
	// med.addNum(6);
	// med.addNum(10);
	// med.addNum(2);
	// med.addNum(6);
	// med.addNum(5);
	// med.addNum(0);
	// med.addNum(6);
	// med.addNum(3);
	// med.addNum(1);
	// med.addNum(0);
	// med.addNum(0);
	obj->addNum(1);
	obj->addNum(2);
	cout << obj->findMedian() << endl;
	obj->addNum(3);
	cout << obj->findMedian() << endl;
}