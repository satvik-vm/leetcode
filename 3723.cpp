#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string answer(num, '0');
        int index = 0;
        while(sum > 0){
            if(sum >= 9){
                if(((num - index) * 9) < sum)    return "";
                answer[index] = '9';
                sum -= 9;
            }
            else{
                answer[index] = sum + '0';
                sum = 0;
            }
            index++;
        }
        return answer;
    }
};