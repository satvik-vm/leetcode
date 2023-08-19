#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define SIZE 26

using namespace std;

string removeDuplicateLetters(string s)
{
	int n = s.size();
	stack<char> st;
	vector<int> lastPos(SIZE, -1);
	vector<bool> isVisited(SIZE, false);
	for (int i = 0; i < n; i++)
	{
		lastPos[s[i] - 'a'] = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isVisited[s[i] - 'a'])
		{
			while (!st.empty() && st.top() > s[i] && lastPos[st.top() - 'a'] > i)
			{
				isVisited[st.top() - 'a'] = false;
				st.pop();
			}
			isVisited[s[i] - 'a'] = true;
			st.push(s[i]);
		}
	}
	string answer = "";
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}
	// reverse(answer.begin(), answer.end());
	return answer;
}

int main(){
	string s = "abacaba";
	cout << removeDuplicateLetters(s) << endl;
}