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

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> nums;
    
    int M = (int) matrix.size();
    if (M == 0) {
        return nums;
    }
    int N = (int) matrix[0].size();
    
    int start = 0;
    int tM = M;
    int tN = N;
    
    while (tM > 0 && tN > 0) {
        if(tM == 1 && tN ==1){
            nums.push_back(matrix[start][start]);
        }
        else if (tM == 1 && tN > 1) {
            for (int i = 0; i < tN; i++) {
                nums.push_back(matrix[start][start+i]);
            }
        }
        else if ( tM > 1 && tN == 1){
            for (int i = 0; i < tM; i++) {
                nums.push_back(matrix[start+i][start]);
            }
        }
        else{
            for (int i = 0; i < tN; i++) {
                nums.push_back(matrix[start][start+i]);
            }
            for (int j = 1; j < tM - 1; j++) {
                nums.push_back(matrix[start+j][start+tN-1]);
            }
            for (int i = 0; i < tN; i++) {
                nums.push_back(matrix[start+tM-1][start+tN-1-i]);
            }
            for (int j = 1; j < tM - 1; j++) {
                nums.push_back(matrix[start+tM-1-j][start]);
            }
        }
        tM-=2;
        tN-=2;
        start++;
    }
    
    
    return nums;
}

int main()
{
    int N,M;
    cin>>M>>N;
    vector<vector<int>> matrix(M,vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0 ; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout<<endl;
    
//    nums.push_back(1);
    
    vector<int> nums = spiralOrder(matrix);
    for (int i = 0 ; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    
    return 1;
}

