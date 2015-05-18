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

void swapCirle(int& a,int& b,int& c,int& d)
{
    int tmp = a;
    a = d;
    d = c;
    c = b;
    b = tmp;
}

void rotate(vector<vector<int>>& matrix)
{
    int start = 0;
    int N = (int) matrix.size();
    
    while (N > 1) {
        for (int i = 0; i < N-1; i++) {
            swapCirle(matrix[start][start+i], matrix[start+i][start+N-1], matrix[start+N-1][start+N-1-i], matrix[start+N-1-i][start]);
        }
        start++;
        N-=2;
    }
}

int main()
{
    int N;
    cin>>N;
    vector<vector<int>> matrix(N,vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout<<endl;

    rotate(matrix);
    
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 1;
}

