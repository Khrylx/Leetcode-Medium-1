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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    if (obstacleGrid.size() == 0) {
        return 0;
    }
    
    for (int i = 0 ; i < obstacleGrid.size(); i++) {
        for (int j = 0; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
            }
            else{
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                }
                else{
                    obstacleGrid[i][j] = (i>0?obstacleGrid[i-1][j]:0) + (j>0?obstacleGrid[i][j-1]:0);
                }
            }
        }
    }
    
    return obstacleGrid.back().back();
}


int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> obstacles(m,vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacles[i][j];
        }
    }
    cout << uniquePathsWithObstacles(obstacles)<<endl;
    return 1;
}

