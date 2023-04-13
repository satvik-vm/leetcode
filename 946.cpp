#include <iostream>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> vec;
    int i = 0, j = 0;
    while(i < pushed.size() && j < popped.size()){
        if(pushed[i] == popped[j]){
            i++;
            j++;
        }else{
            if(vec.size() > 0 && vec.back() == popped[j]){
                vec.pop_back();
                j++;
            }else{
                vec.push_back(pushed[i]);
                i++;
            }
        }
    }
    while(j < popped.size()){
        if(vec.back() == popped[j]){
            vec.pop_back();
            j++;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,1,2};
    cout << validateStackSequences(pushed, popped) << endl;
}

