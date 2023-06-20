#include <iostream>
#include <vector>

using namespace std;

string convert(string s)
{
	string str = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		if (s[i] >= 97 && s[i] <= 122)
			str += s[i];
	}
	return str;
}
bool isPalindrome(string s)
{
	string str = convert(s);
	cout << str << endl;
	int start = 0, end = str.size() - 1;
	while (start < end)
	{
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}
	return true;
}

int main(){
	string s = "0P";
	cout << isPalindrome(s) << endl;
}