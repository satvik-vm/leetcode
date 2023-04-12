#include <iostream>
#include <vector>
#include <string>

using namespace std;

string simplifyPath(string path) {
    string base = "/";
    vector<string> stack;
    string temp = "";
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << endl;
        if(path[i] == '/'){
            if(temp == ".."){
                if(!stack.empty()){
                    stack.pop_back();
                }
            }
            else if(temp != "." && temp != ""){
                stack.push_back(temp);
            }
            temp = "";
        }
        else{
            temp += path[i];
        }
    }
    if(temp == ".."){
        if(!stack.empty()){
            stack.pop_back();
        }
    }
    else if(temp != "." && temp != ""){
        stack.push_back(temp);
    }
    string answer = base;
    for(int i = 0; i < stack.size(); i++){
        answer += stack[i] + "/";
    }
    if(answer.size() > 1)    answer.pop_back();
    return answer;
}

int main(){
    string path = "/a//b////c/d//././/..";
    cout << simplifyPath(path) << endl;
}