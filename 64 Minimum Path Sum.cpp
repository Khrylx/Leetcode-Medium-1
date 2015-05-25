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

int minPathSum(vector<vector<int>>& grid)
{
    if (grid.size() == 0) {
        return 0;
    }
    for (int i = 1; i < grid.size(); i++) {
        grid[i][0] += grid[i-1][0];
    }
    for (int i = 1; i < grid[0].size(); i++) {
        grid[0][i] += grid[0][i-1];
    }
    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[0].size(); j++) {
            grid[i][j] = grid[i][j] + min(grid[i-1][j],grid[i][j-1]);
        }
    }
    
    return grid.back().back();
}


int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid)<<endl;
    return 1;
}

