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
#include <unordered_set>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    static bool sorted = false;
    if (!sorted) {
        sort(candidates.begin(), candidates.end());
        sorted = true;
    }
    
    
    vector<vector<int>> solutions;
    if (candidates.size() == 0) {
        return solutions;
    }
    
    int candidate = candidates.back();
    
    for (int i = 0; i <= target / candidate; i++) {
        if (target == i * candidate) {
            vector<int> tmpSol;
            for (int k = 0 ; k < i; k++) {
                tmpSol.push_back(candidate);
            }
            solutions.push_back(tmpSol);
        }
        else{
            candidates.pop_back();
            vector<vector<int>> tmpSolutions = combinationSum(candidates, target - i*candidate);
            candidates.push_back(candidate);
            for (int j = 0; j < tmpSolutions.size(); j++) {
                for (int k = 0 ; k < i; k++) {
                    tmpSolutions[j].push_back(candidate);
                }
                solutions.push_back(tmpSolutions[j]);
            }
        }
        
    }
    
    return  solutions;
    
}

int main()
{
    int target = 11;
    vector<int> candidates;
    candidates.push_back(8);
    candidates.push_back(7);
    candidates.push_back(4);
    candidates.push_back(3);
    vector<vector<int>> soluton = combinationSum(candidates, target);
    return 1;
}

