#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define DICE 6

using namespace std;

int getPos(int i, int j, int n)
{
	int num = (i * n);
	if ((i % 2 == 0) ^ (n % 2 != 0))
	{
		num += j + 1;
	}
	else
	{
		num += n - j;
	}
	return n * n - num + 1;
}
int snakesAndLadders(vector<vector<int>> &board)
{
	map<int, int> mp;
	int n = board.size();
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] != -1)
			{
				mp[getPos(i, j, n)] = board[i][j];
			}
		}
	}
	queue<pair<int, int>> q; // first: pos, second: steps
	pair<int, int> temp;
	vector<bool> isVisited(n * n, false);
	q.push({1, 0});
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.first >= n * n)
		{
			return temp.second;
		}
		if (isVisited[temp.first])
		{
			continue;
		}
		for (int i = DICE; i >= 1; i--)
		{
			if (mp[temp.first + i] == 0)
			{
				q.push({temp.first + i, temp.second + 1});
			}
			else
			{
				q.push({mp[temp.first + i], temp.second + 1});
			}
		}
		isVisited[temp.first] = true;
	}
	return -1;
}