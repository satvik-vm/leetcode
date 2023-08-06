#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int n = gas.size();
	int curr_gas = 0, total = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		total += gas[i] - cost[i];
		curr_gas += gas[i] - cost[i];
		if (curr_gas < 0)
		{
			start = i + 1;
			curr_gas = 0;
		}
	}
	if (total < 0)
		return -1;
	return start;
}