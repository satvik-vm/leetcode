#include <iostream>
#include <vector>
#include <istream>
#include <sstream>
#include <map>

using namespace std;

vector<string> subdomainVisits(vector<string> &cpdomains)
{
	map<string, int> mp;
	int vecSize = cpdomains.size();
	for (int i = 0; i < vecSize; i++)
	{
		stringstream s(cpdomains[i]);
		vector<string> split_str;
		string str;
		while (getline(s, str, ' '))
		{
			split_str.push_back(str);
		}
		int visits = stoi(split_str[0]);
		string domain = split_str[1];
		mp[domain] += visits;
		for (int j = 0; j < domain.size(); j++)
		{
			if (domain[j] == '.')
			{
				mp[domain.substr(j + 1, domain.size() - j - 1)] += visits;
			}
		}
	}
	vector<string> answer;
	for (auto [str, count] : mp)
	{
		answer.push_back(to_string(count) + " " + str);
	}
	return answer;
}