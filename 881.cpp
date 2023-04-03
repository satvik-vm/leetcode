#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int result = 0, size = people.size();
    sort(people.begin(), people.end());
    int left = 0, right = size - 1, sum = 0;
    while(left <= right){
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }   else {
            right--;
        }
        result++;
    }
    return result;
}

int main(){
    vector<int> people = {3, 5, 3, 4};
    int limit = 5;
    cout << numRescueBoats(people , limit) << endl;
}