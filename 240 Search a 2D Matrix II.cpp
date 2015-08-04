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
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    
    int row = 0;
    int col = n-1;
    
    while (row < m && col >= 0) {
        int cur = matrix[row][col];
        if (cur == target) {
            return true;
        }
        else if (cur < target){
            row++;
        }
        else{
            col--;
        }
    }
    return false;
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
    
    bool res = searchMatrix(matrix, 13);
    
    return 1;
}
