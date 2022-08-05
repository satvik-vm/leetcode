#include <iostream>
#include <algorithm>

using namespace std;

int mirrorReflection(int p, int q) {
    int gcd = __gcd(p, q);
    p /= gcd;
    q /= gcd;

    if(q % 2 == 0)  return 0;
    if(p % 2 == 0)  return 2;
    return 1;
}

int main(){
    int p = 3, q = 1;
    int ans = mirrorReflection(p, q);
    cout << ans << endl;
}