#include <iostream>
#include <vector>

using namespace std;

int integerReplacement(long long n)
{
	if (n == 0)
		return 1e7;
	if (n == 1)
		return 0;
	int answer;
	if (n % 2 == 0)
	{
		answer = 1 + integerReplacement(n / 2);
	}
	else
	{
		answer = 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
	}
	return answer;
}