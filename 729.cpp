#include <iostream>
#include <vector>
#include <utility>
#include <chrono>

using namespace std;


class MyCalendar {
private:
    vector<pair<int, int>> list;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto itt : list){
            if((itt.second > start) && (itt.first < end)) {
                return false;
            }
        }
        list.push_back(make_pair(start, end));
        return true;
    }
};

int main(){
    chrono::high_resolution_clock::time_point time_start, time_end;
    chrono::microseconds time_diff;

    time_start = chrono::high_resolution_clock::now();
    MyCalendar *obj = new MyCalendar();
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << "created in " << time_diff.count() << " microseconds" << endl << endl;

    int start = 10, end = 20;
    time_start = chrono::high_resolution_clock::now();
    bool ans = obj->book(start, end);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << ans << endl;
    cout << "query in " << time_diff.count() << " microseconds" << endl << endl;

    start = 15, end = 25;
    time_start = chrono::high_resolution_clock::now();
    ans = obj->book(start, end);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << ans << endl;
    cout << "query in " << time_diff.count() << " microseconds" << endl << endl;

    start = 20, end = 30;
    time_start = chrono::high_resolution_clock::now();
    ans = obj->book(start, end);
    time_end = chrono::high_resolution_clock::now();
    time_diff = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    cout << ans << endl;
    cout << "query in " << time_diff.count() << " microseconds" << endl << endl;
}