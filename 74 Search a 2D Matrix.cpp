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

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int left = 0;
    int right = (int)matrix.size()-1;
    
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    
    if (matrix[left][0] == target || matrix[right][0] == target) {
        return true;
    }
    if (matrix[left][0] > target) {
        return false;
    }
    
    int newPos = 0;
    if (matrix[right][0] < target || matrix.size() == 1) {
        newPos = right;
    }
    else if(matrix[left+1][0] > target){
        newPos = left;
    }
    else{
        while (left+1 < right) {
            newPos = (left + right) / 2;
            if (matrix[newPos][0] == target) {
                return true;
            }
            else if(matrix[newPos][0] > target){
                right = newPos;
            }
            else if(matrix[newPos][0] < target){
                if(matrix[newPos+1][0] > target){
                    break;
                }
                else{
                    left = newPos;
                }
            }
        }

    }
    
    left = 0;
    right = (int)matrix[0].size()-1;
    
    if (matrix[newPos][left] == target || matrix[newPos][right] == target) {
        return true;
    }
    if (matrix[newPos][right] < target) {
        return false;
    }
    
    while (left+1 < right) {
        int newPosEx = (left+right)/2;
        if (matrix[newPos][newPosEx] == target) {
            return true;
        }
        else if(matrix[newPos][newPosEx] < target){
            left = newPosEx;
        }
        else if(matrix[newPos][newPosEx] > target){
            right = newPosEx;
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
    
    cout << searchMatrix(matrix, 2) <<endl;
    
    
    return 1;
}

