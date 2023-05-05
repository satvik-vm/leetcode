#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int bulbSwitch(int n) {
    return sqrt(n);
}

int main(){
    int n = 1000;
    cout << bulbSwitch(n) << endl;
}