#include <iostream>

using namespace std;

double myPow(double x, int n) {
    double answer = 1.0;
    long _n = n;
    if(_n < 0)  _n *= -1;
    while(_n > 0){
        if(_n % 2 == 1){
            answer *= x;
            _n -= 1;
        }
        else{
            x = x * x;
            _n = _n / 2;
        }
    }
    if(n < 0)   answer = (double)(1) / (double)answer;
    return answer;
}

int main(){
    double x = 2;
    int n = -2;
    cout << myPow(x, n) << endl;
}

