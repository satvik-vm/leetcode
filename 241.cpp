#include <iostream>
#include <vector>

using namespace std;

int operate(int x, int y, char op)
{
	if (op == '+')
		return x + y;
	if (op == '*')
		return x * y;
	if (op == '-')
		return x - y;
	return 1;
}

vector<int> diffWaysToCompute(string expression)
{
	vector<int> result;
	bool isNumber = true;
	for (int i = 0; i < expression.size(); i++)
	{
		if (!isdigit(expression[i]))
		{
			isNumber = false;
			vector<int> left = diffWaysToCompute(expression.substr(0, i));
			vector<int> right = diffWaysToCompute(expression.substr(i + 1));
			for (int left_i : left)
			{
				for (int right_i : right)
				{
					result.push_back(operate(left_i, right_i, expression[i]));
				}
			}
		}
	}
	if (isNumber)
		result.push_back(stoi(expression));
	return result;
}