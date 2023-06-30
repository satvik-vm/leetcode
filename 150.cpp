#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string itt: tokens){
			char ch = itt[0];
			if(itt.size() > 1 || (ch != '+' && ch != '-' && ch != '*' && ch != '/')){
				st.push(stoi(itt));
			}
            else if(ch == '+'){
				cout << "--SUM--" << endl;
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int ans = num1 + num2;
                st.push(ans);
				cout << num1 << " " << num2 << " " << ans << endl;
				cout << "--SUM END--" << endl;
            }
            else if(ch == '-'){
				cout << "--DIFF--" << endl;
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int ans = num2 - num1;
                st.push(ans);
				cout << num1 << " " << num2 << " " << ans << endl;
				cout << "--DIFF END--" << endl;
            }
            else if(ch == '*'){
				cout << "--MULT--" << endl;
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int ans = num1 * num2;
                st.push(ans);
				cout << num1 << " " << num2 << " " << ans << endl;
				cout << "--MULT END--" << endl;
            }
            else if(ch == '/'){
				cout << "--DIV--" << endl;
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int ans = num2 / num1;
                st.push(ans);
				cout << num1 << " " << num2 << " " << ans << endl;
				cout << "--DIV END--" << endl;
            }
        }
        return st.top();
    }
};

int main(){
	Solution *obj = new Solution();
	vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << obj->evalRPN(tokens) << endl;
}