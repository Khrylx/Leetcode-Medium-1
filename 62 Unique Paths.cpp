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

int uniquePaths(int m, int n)
{
    vector<vector<int>> pathNums(m,vector<int>(n));
    
    for (int i =  0; i < m; i++) {
        pathNums[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        pathNums[0][i] = 1;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            pathNums[i][j] = pathNums[i-1][j] + pathNums[i][j-1];
        }
    }
    
    return pathNums[m-1][n-1];
}


int main()
{
    cout << uniquePaths(4, 4)<<endl;
    return 1;
}

