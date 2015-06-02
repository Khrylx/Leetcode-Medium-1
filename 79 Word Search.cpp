//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool findHelper(vector<vector<char>>& board, int i, int j, int index, string& word)
{
    if (index == word.length()) {
        return true;
    }
    
    bool res = false;
    
    if (i-1 >= 0 && board[i-1][j] == word[index]) {
        board[i-1][j] = 0;
        res = findHelper(board, i-1, j, index+1, word);
        board[i-1][j] = word[index];
        if (res) {
            return true;
        }
    }
    
    if (i+1 <board.size() && board[i+1][j] == word[index]) {
        board[i+1][j] = 0;
        res = findHelper(board, i+1, j, index+1, word);
        board[i+1][j] = word[index];
        if (res) {
            return true;
        }
    }

    if (j-1 >= 0 && board[i][j-1] == word[index]) {
        board[i][j-1] = 0;
        res = findHelper(board, i, j-1, index+1, word);
        board[i][j-1] = word[index];
        if (res) {
            return true;
        }
    }

    if (j+1 >= 0 && board[i][j+1] == word[index]) {
        board[i][j+1] = 0;
        res = findHelper(board, i, j+1, index+1, word);
        board[i][j+1] = word[index];
        if (res) {
            return true;
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    if (word.length() == 0 || board.size() == 0 || board[0].size() == 0) {
        return false;
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                board[i][j] = 0;
                bool res = findHelper(board, i, j, 1, word);
                board[i][j] = word[0];
                if (res) {
                    return true;
                }
            }
        }
    }
    
    return false;
    
}


int main(){
    int M,N;
    cin >> M >> N;
    vector<vector<char>> board(M,vector<char>(N));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    
    cout << exist(board, "ABCB");
    
    
    return 1;
}

