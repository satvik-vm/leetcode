#include <iostream>
#include <vector>

using namespace std;

bool canBehIndex(vector<int> citations, int h)
{
	int n = citations.size();
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (citations[i] >= h)
			answer++;
	}
	return answer >= h;
}
int hIndex(vector<int> &citations)
{
	if (citations.size() == 1)
		return citations[0] >= 1;
	int answer = 0;
	int n = citations.size();
	int low = 0, high = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (canBehIndex(citations, mid))
		{
			cout << "Can be, " << mid << endl;
			low = mid + 1;
		}
		else
		{
			cout << "Can not be, " << mid << endl;
			high = mid - 1;
		}
	}
	return low - 1;
}

int main(){
	vector<int> citations = {3,0,6,1,5};
	cout << hIndex(citations) << endl;
}