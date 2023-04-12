#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> closestDivisors(int num) {
    int num_1 = num + 1;
    int num_2 = num + 2;
    vector<int> answer_1={0, INT_MAX}, answer_2={0, INT_MAX};
    for(int i = 1;i <= num_1; i++){
        if(num_1 % i == 0){
            int ans = num_1 / i;
            if(abs(answer_1[0]-answer_1[1]) > abs(ans - i)) answer_1 = {i, ans};
        }
    }

    for(int i = 1;i <= num_2; i++){
        if(num_2 % i == 0){
            int ans = num_2 / i;
            if(abs(answer_2[0]-answer_2[1]) > abs(ans - i)) answer_2 = {i, ans};
        }
    }

    if(abs(answer_1[0]-answer_1[1]) > abs(answer_2[0]-answer_2[1])) return answer_2;
    return answer_1;
}

int main(){
    int num = 688427155;
    vector<int> result = closestDivisors(num);
    for(auto itt: result){
        cout << itt << " ";
    }
    cout << endl;
}
