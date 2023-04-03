#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
private:
    vector<int> vec;
    int total;
public:
    Solution(vector<int>& w) {
        this->vec.push_back(w[0]);
        for(int i = 1;i < w.size();i++){
            this->vec.push_back(vec[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        int random = rand() % vec[vec.size()-1];
        auto it = upper_bound(vec.begin(), vec.end(), random);
        return it - vec.begin();
    }
};

int main(){
    vector<int> w = {1, 3};
    Solution* obj = new Solution(w);
    int param_1 = obj->pickIndex();
    cout << param_1 << endl;
}
 