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
#include <unordered_set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }
    
    bool firstLineZero = false;
    bool firstColZero = false;
    
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == 0) {
            firstLineZero = true;
            break;
        }
    }
    
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if (firstLineZero)
        matrix[0].assign(matrix[0].size(), 0);
    
    if (firstColZero) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
    
    
    return;
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    setZeroes(matrix);
    
    cout<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 1;
}

