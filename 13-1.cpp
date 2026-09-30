// for https://leetcode.com/problems/roman-to-integer/description/, it says only six combinations
//can exists, as only place left can be smaller and hence used for subtraction
// to expolate, what if the subtraction space can go as far back as right most
// bigger number than the one now

//* Solution submitted to leetcode. Passed

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	int romanToInt(string roman){
		unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

		stack<vector<int>> st;	//value, to_add
		int answer = 0;

		for(char ch: roman){
			int value = map[ch], to_add = 0, to_sub = 0;
			if(!st.empty() && st.top()[0] < value){
				while(!st.empty() && st.top()[0] < value){
					to_sub += st.top()[1];
					st.pop();
				}
				to_add = value - to_sub;
			}
			else{
				to_add = value;
			}
			// cout << value << " " << to_add << endl;
			st.push({value, to_add});
			answer += to_add;
			answer -= to_sub;	//as values in to_sub were added to answer previously
		}

		return answer;
	}
};


int main(){
	vector<string> roman = {"III", "LVIII", "MCMXCIV"};
	vector<int> answer = {3, 58, 1994};
	Solution sol;
	bool all_correct = true;
	for(int i = 0; i < answer.size(); i++){
		int predict = sol.romanToInt(roman[i]);
		if(predict != answer[i]){
			cout << "ANSWER NOT MATCHING FOR " << roman[i] << " " << ". Predict: " << predict << endl;
			all_correct = false;
		}
	}
	if(all_correct){
		cout << "Test Case Passed" << endl;
	}
}