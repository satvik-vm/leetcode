#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    string result = "", curr_result = "";
	vector<string> vec;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			cout << i << " " << curr_result << endl;
			if(curr_result != "")	vec.push_back(curr_result);
			curr_result = "";
		}	else {
			curr_result += s[i];
		}
	}
	if(curr_result != "")	vec.push_back(curr_result);
	for(int i = vec.size() - 1; i >= 0; i--){
		result += vec[i];
		result += " ";
	}
	result.pop_back();
	return result;
}

int main(){
	string str = " hello world ";
	cout << reverseWords(str);
}