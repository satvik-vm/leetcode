#include <iostream>
#include <vector>
#include <climits>

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
			// cout << bit << endl;
			if (curr->children[1 - bit] != NULL)
			{
				max_num = max_num | (1 << i);
				curr = curr->children[1 - bit];
			}
			else
			{
				curr = curr->children[bit];
			}
		}
		return max_num;
	}
};

int findMaximumXOR(vector<int> &nums)
{
	Trie *obj = new Trie;
	for (int i = 0; i < nums.size(); i++)
		obj->insert(nums[i]);
	int max_num = INT_MIN;
	for (int i = 0; i < nums.size(); i++)
	{
		max_num = max(max_num, obj->getMax(nums[i]));
	}
	return max_num;
}