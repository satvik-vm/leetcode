#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string removeKdigits(string num, int k)
{
	stack<char> st;
	int n = num.size();
	if (n <= k)
		return "0";
	st.push(num[0]);
	for (int i = 1; i < n; i++)
	{
		if (st.empty() && num[i] == '0')
			continue;
		while (k > 0 && !st.empty() && st.top() > num[i])
		{
			// cout << num[i] << endl;
			st.pop();
			k--;
		}
		st.push(num[i]);
	}
	while (k > 0 && !st.empty())
	{
		st.pop();
		k--;
	}
	string answer = "";
	while (!st.empty())
	{
		// cout << st.top() << endl;
		answer += st.top();
		st.pop();
	}
	reverse(answer.begin(), answer.end());
	while (answer[0] == '0' && answer.size() > 1)
	{
		answer.erase(answer.begin());
	}
	return answer;
}