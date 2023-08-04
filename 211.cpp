#include <iostream>
#include <vector>
#define ALPHABET 26

using namespace std;

struct TrieNode
{
	TrieNode *childrenNode[ALPHABET] = {NULL};
	int wordEnd = 0;
};

class WordDictionary
{
private:
	TrieNode *root;

public:
	WordDictionary()
	{
		root = new TrieNode;
	}

	void addWord(string word)
	{
		TrieNode *curr = root;
		for (char ch : word)
		{
			if (curr->childrenNode[ch - 'a'] == NULL)
			{
				curr->childrenNode[ch - 'a'] = new TrieNode;
			}
			curr = curr->childrenNode[ch - 'a'];
		}
		curr->wordEnd++;
	}

	bool searchUtils(string word, TrieNode *node, int index)
	{
		if (index == word.size())
			return node->wordEnd;
		if (word[index] == '.')
		{
			for (int i = 0; i < ALPHABET; i++)
			{
				if (node->childrenNode[i] != NULL && searchUtils(word, node->childrenNode[i], index + 1))
					return true;
			}
		}
		else if (node->childrenNode[word[index] - 'a'] != NULL)
			return searchUtils(word, node->childrenNode[word[index] - 'a'], index + 1);
		return false;
	}

	bool search(string word)
	{
		TrieNode *curr = root;
		return searchUtils(word, curr, 0);
	}
};

int main(){
	WordDictionary *obj = new WordDictionary;
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	cout << obj->search(".ad") << endl;
	cout << obj->search("b..") << endl;
}