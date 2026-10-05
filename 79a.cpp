#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> init_cords = initial_cords(board, word[0]);
        bool is_present = false;
        for(int i = 0; i < init_cords.size(); i++){
            vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
            is_present = is_present || recur(board, init_cords[i], word, 0, isVisited);
        }
        return is_present;
    }

    vector<vector<int>> initial_cords(vector<vector<char>>& board, char init_ch){
        vector<vector<int>> cords;
        for(int row = 0; row < board.size(); row++){
            for(int column = 0; column < board[row].size(); column++){
                if(board[row][column] == init_ch){
                    cords.push_back({row, column});
                }
            }
        }
        return cords;
    }


    bool recur(vector<vector<char>>& board, vector<int> cords, string word, int index, vector<vector<bool>>& isVisited){
        if(index == word.size() - 1){
            return true;
        }

        int row = cords[0], column = cords[1];
        isVisited[row][column] = true;
        bool to_return = false;

        if(row > 0){
            if(!isVisited[row - 1][column] && board[row - 1][column] == word[index + 1]){
                to_return = to_return || recur(board, {row - 1, column}, word, index + 1, isVisited);
            }
        }

        if(column > 0){
            if(!isVisited[row][column - 1] && board[row][column - 1] == word[index + 1]){
                to_return = to_return || recur(board, {row, column - 1}, word, index + 1, isVisited);
            }
        }

        if(row < board.size() - 1){
            if(!isVisited[row + 1][column] && board[row + 1][column] == word[index + 1]){
                to_return = to_return || recur(board, {row + 1, column}, word, index + 1, isVisited);
            }
        }

        if(column < board[0].size() - 1){
            if(!isVisited[row][column + 1] && board[row][column + 1] == word[index + 1]){
                to_return = to_return || recur(board, {row, column + 1}, word, index + 1, isVisited);
            }
        }

        isVisited[row][column] = false;

        return to_return;
    }
};