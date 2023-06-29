#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	map<string, vector<string>> mp;
	for (auto itt : strs)
	{
		string sorted = itt;
		sort(sorted.begin(), sorted.end());
		mp[sorted].push_back(itt);
	}
	vector<vector<string>> answer;
	for (auto [key, value] : mp)
	{
		answer.push_back(value);
	}
	return answer;
}

int main()
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> answer = groupAnagrams(strs);
	for (auto itt1 : answer)
	{
		for (string itt2 : itt1)
			cout << itt2 << " ";
		cout << endl;
	}
}