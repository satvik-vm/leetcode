#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int rows = box.size();
    int columns = box[0].size();

    vector<vector<char>> toreturn(columns, vector<char> (rows, '.'));

    for(int i = 0; i < rows; ++i){
        int pointer = columns - 1;
        for(int j = columns - 1; j >= 0; --j){
            if(box[i][j] != '.'){
                if(box[i][j] == '#')    toreturn[pointer--][rows-i-1] = '#';
                else if(box[i][j] == '*'){
                    toreturn[j][rows-i-1] = '*';
                    pointer = j - 1;
                }
            }
        }
    }

    return toreturn;
}

int main(){
    vector<vector<char>> box = {{'#','#','*','.','*','.'},
                                {'#','#','#','*','.','.'},
                                {'#','#','#','.','#','.'}};
    // vector<vector<char>> box = {{'#'}};
    vector<vector<char>> ans = rotateTheBox(box);
    for(auto itt1 : ans){
        for(auto itt2 : itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
}