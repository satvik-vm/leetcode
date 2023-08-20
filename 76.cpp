#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

bool check(map<char, int> mp_s, map<char, int> mp_t)
{
	for (auto itt : mp_t)
	{
		if (itt.second > 0 && itt.second > mp_s[itt.first])
			return false;
	}
	return true;
}
string minWindow(string s, string t)
{
	int m = s.size();
	int n = t.size();
	string answer = "";
	if (n > m)
		return "";
	map<char, int> mp_t, mp_s;
	for (int i = 0; i < t.size(); i++)
		mp_t[t[i]]++;
	int start = 0, end = 0, len = INT_MAX;
	while (end < m)
	{
		mp_s[s[end]]++;
		while (start <= end && (mp_s[s[start]] > mp_t[s[start]] || mp_t[s[start]] == 0))
		{
			mp_s[s[start]]--;
			start++;
		}
		if (check(mp_s, mp_t))
		{
			if (len > end - start + 1)
			{
				len = end - start + 1;
				answer = s.substr(start, len);
			}
			mp_s[s[start]]--;
			start++;
		}
		end++;
	}
	return answer;
}