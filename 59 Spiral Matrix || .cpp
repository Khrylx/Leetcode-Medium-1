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

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n,vector<int>(n));
    
    int index = 1;
    int start = 0;
    
    while (n > 0) {
        if (n == 1) {
            matrix[start][start] = index++;
        }
        else{
            for (int i = 0; i < n-1; i++) {
                matrix[start][start+i] = index++;
            }
            for (int i = 0; i < n-1; i++) {
                matrix[start+i][start+n-1] = index++;
            }
            for (int i = 0; i < n-1; i++) {
                matrix[start+n-1][start+n-1-i] = index++;
            }
            for (int i = 0; i < n-1; i++) {
                matrix[start+n-1-i][start] = index++;
            }
        }
        
        start++;
        n-=2;
    }
    
    return matrix;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> matrix = generateMatrix(N);
    
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
    
    return 1;
}

