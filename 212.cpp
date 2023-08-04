#include <iostream>
#include <vector>
#define ALPHABETS 26

using namespace std;

struct TrieNode
{
	TrieNode *children[ALPHABETS] = {NULL};
	string word = "";
};

TrieNode *insert(vector<string> words)
{
	TrieNode *root = new TrieNode;
	TrieNode *curr = root;
	for (string word : words)
	{
		for (char ch : word)
		{
			if (curr->children[ch - 'a'] == NULL)
			{
				curr->children[ch - 'a'] = new TrieNode;
			}
			curr = curr->children[ch - 'a'];
		}
		curr->word = word;
		curr = root;
	}
	return root;
}

void dfs(vector<vector<char>> &board, int row, int column, vector<string> &answer, TrieNode *root)
{
	TrieNode *curr = root;
	if (board[row][column] == '#' || curr->children[board[row][column] - 'a'] == NULL)
		return;
	curr = curr->children[board[row][column] - 'a'];
	if (curr->word != "")
	{
		answer.push_back(curr->word);
		curr->word = "";
	}
	char ch = board[row][column];
	board[row][column] = '#';
	if (row > 0)
		dfs(board, row - 1, column, answer, curr);
	if (row < board.size() - 1)
		dfs(board, row + 1, column, answer, curr);
	if (column > 0)
		dfs(board, row, column - 1, answer, curr);
	if (column < board[0].size() - 1)
		dfs(board, row, column + 1, answer, curr);
	board[row][column] = ch;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
	insert(words);
	vector<string> answer;
	TrieNode *root = insert(words);
	for (int row = 0; row < board.size(); row++)
	{
		for (int column = 0; column < board[0].size(); column++)
		{
			dfs(board, row, column, answer, root);
		}
	}
	return answer;
}