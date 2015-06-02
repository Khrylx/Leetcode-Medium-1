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

void combineHelper(vector<vector<int>>& solutions, vector<int>& digits, int index, int k, int n)
{
    if (k == 0) {
        solutions.push_back(digits);
        return;
    }
    if (index > n) {
        return;
    }
    
    digits.push_back(index);
    combineHelper(solutions, digits, index+1, k-1, n);
    digits.pop_back();
    
    combineHelper(solutions, digits, index+1, k, n);
    
    
    return;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> solutions;
    vector<int> digits;
    
    if (k == 0 || n < k) {
        return solutions;
    }
    
    combineHelper(solutions, digits, 1, k, n);
    
    return solutions;
}

int main(){
    
    vector<vector<int>> S = combine(4, 2);
    
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    return 1;
}

