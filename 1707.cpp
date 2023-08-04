#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode
{
	TrieNode *children[2] = {NULL};
};

class Trie
{
private:
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode;
	}

	void insert(int num)
	{
		TrieNode *curr = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (curr->children[bit] == NULL)
			{
				curr->children[bit] = new TrieNode;
			}
			curr = curr->children[bit];
		}
	}

	int getMax(int num)
	{
		TrieNode *curr = root;
		int max_num = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (curr->children[!bit] != NULL)
			{
				max_num = max_num | (1 << i);
				curr = curr->children[!bit];
			}
			else
			{
				curr = curr->children[bit];
			}
		}
		return max_num;
	}
};

static bool comp(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
	Trie *obj = new Trie;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < queries.size(); i++)
	{
		queries[i].push_back(i);
	}
	sort(queries.begin(), queries.end(), comp);
	vector<int> answer(queries.size());
	int pt = 0;
	for (int i = 0; i < queries.size(); i++)
	{
		while (pt < nums.size() && nums[pt] <= queries[i][1])
		{
			obj->insert(nums[pt]);
			pt++;
		}
		if (pt == 0)
			answer[queries[i][2]] = -1;
		else
			answer[queries[i][2]] = obj->getMax(queries[i][0]);
	}
	return answer;
}