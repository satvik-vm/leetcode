#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

string countAndSay(int n) {
	if(n == 1)	return "1";
	string returned = countAndSay(n-1);
	cout << n << " " << returned << " " << returned.size() << endl;
	string to_return = "";
	int count = 1;
	for(int i = 0; i < returned.size() - 1; i++){
		cout << "i: "<< i << " "<< returned.size() << endl;
		if(returned[i] == returned[i+1]){
			count++;
		}
		else{
			to_return += to_string(count) + string(1, returned[i]);
			count = 1;
		}
	}
	to_return += to_string(count) + string(1, returned.back());


	// cout << "FINAL TO RETURN " << to_return << endl; 
	return to_return;
}

int main(){
	int n = 4;
	cout << countAndSay(n) << endl;
}