#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
private:
    const long max_rand = 1000000L;
    double radius, x_center, y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double upper_bound = this->radius;
        double lower_bound = 0;
        double dis = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        double angle = rand() % 360 * 0.0174533;
        double sin_num = sin(angle);
        double cos_num = cos(angle);
        double x = this->x_center + (dis * cos_num);
        double y = this->y_center + (dis * sin_num);
        vector<double> answer = {x, y};
        return answer;
    }
};

int main(){
    double radius = 1.0;
    double x_center = 0;
    double y_center = 0;
    Solution *obj = new Solution(radius, x_center, y_center);
    vector<double> result = obj->randPoint();
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

