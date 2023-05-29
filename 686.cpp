#include <iostream>
#include <vector>

using namespace std;

int repeatedStringMatch(string a, string b) {
    string a_temp = a;
	int result = 1;
	while(a.size() < b.size()){
		a += a_temp;
		result++;
	}
	if(a.find(b) != -1)	return result;
	a += a_temp;
	result++;
	if(a.find(b) != -1)	return result;
	return -1;
}

int main(){
	string a = "a", b = "aa";
	cout << repeatedStringMatch(a, b) << endl;
}