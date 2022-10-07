#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class MapSum {
private:
    unordered_map<string, int> map;
public:
    MapSum() {
        cout << "MapSum" << endl;
    }
    
    void insert(string key, int val) {
        cout << "Insert " << key << " " << val << endl;
        map[key] = val;
    }
    
    int sum(string prefix) {
        cout << "Sum begin" << endl;
        int sum = 0;
        for(auto itt : map){
            cout << itt.first << " " << itt.second << endl;
            if(itt.first.substr(0, prefix.size()) == prefix){
                cout << itt.first << endl;
                sum += itt.second;
            }
        }
        cout << "Sum end" << endl;
        return sum;
    }
};

int main(){
    MapSum* obj = new MapSum();
    obj->insert("apple", 3);
    cout << obj->sum("ap") << endl;
    obj->insert("app", 2);
    obj->insert("apple", 2);
    cout << obj->sum("ap") << endl;
}