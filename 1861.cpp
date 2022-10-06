#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int rows = box.size();
    int columns = box[0].size();

    for(int i = 0;i < rows; i++){
        for(int j = columns-1; j >= 0; j--){
            if(box[i][j] == '#'){
                int empty = j + 1;
                while(empty < columns && box[i][empty] == '.') empty++;
                if(empty < columns && box[i][empty] == '.'){
                    box[i][empty] = '#';
                    box[i][j] = '.';
                }   else if(empty - 1 < columns && box[i][empty-1] == '.'){
                    box[i][empty-1] = '#';
                    box[i][j] = '.';
                }
            }
        }
    }

    vector<vector<char>> toreturn;

    for(int i = 0;i < columns; i++){
        vector<char> answer;
        for(int j = rows-1;j >= 0; j--){
            answer.push_back(box[j][i]);
        }
        toreturn.push_back(answer);
    }

    return toreturn;
}

int main(){
    vector<vector<char>> box = {{'#','#','*','.','*','.'},
                                {'#','#','#','*','.','.'},
                                {'#','#','#','.','#','.'}};
    // vector<vector<char>> box = {{'#'}};
    auto start = std::chrono::steady_clock::now();
    vector<vector<char>> ans = rotateTheBox(box);
    auto end = std::chrono::steady_clock::now();
    for(auto itt1 : ans){
        for(auto itt2 : itt1){
            cout << itt2 << " ";
        }
        cout << endl;
    }
    cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds"<< endl;
}