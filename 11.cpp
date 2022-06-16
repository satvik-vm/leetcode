#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size() - 1;
    int area = n * min(height[n], height[0]);
    int end = n;
    int start = 0;
    while(start < end){
        if(height[end] > height[start]) start++;
        else    end--;
        area = max(area, min(height[end], height[start]) * (end - start));
    }
    return area;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
}