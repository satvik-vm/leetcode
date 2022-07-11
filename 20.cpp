#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    for(auto ch : s){
        if(ch == '(' || ch == '{' || ch == '[') stack.push(ch);
        if(!stack.empty()){
            if(ch == ')'){
                if(stack.top() == '('){
                    stack.pop();
                    continue;
                }
                else{
                    break;
                }
            }
            if(ch == '}'){
                if(stack.top() == '{'){
                    stack.pop();
                    continue;
                }
                else{
                    break;
                }
            }
            if(ch == ']'){
                if(stack.top() == '['){
                    stack.pop();
                    continue;
                }
                else{
                    break;
                }
            }
        }
        else return false;
    }
    return stack.empty() ? true : false;
}

int main(){
    string s = "]";
    cout << isValid(s) << endl;
}