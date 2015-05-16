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

void combinationSumHelper(vector<int>& candidates, vector<int>& curVec, int index, int target ,vector<vector<int>>& solutions)
{
    if (target == 0) {
        solutions.push_back(curVec);
        return;
    }
    else if (index == (int)candidates.size()) {
        return;
    }
    
    int candidate = candidates[index];
    int newIndex = index+1;
    while (newIndex < (int)candidates.size() && candidates[newIndex]==candidates[index]) {
        newIndex++;
    }
    
    int N = min(target / candidate,newIndex-index);
    for (int i = 0; i <= N ; i++) {
        
        combinationSumHelper(candidates, curVec, newIndex, target - i*candidate,solutions);
        curVec.push_back(candidate);
    }
    for (int i = 0; i <= N; i++) {
        curVec.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> solutions;
    vector<int> curVec;
    sort(candidates.begin(), candidates.end());
    
    combinationSumHelper(candidates, curVec, 0, target,solutions);
    
    
    return  solutions;
    
}

int main()
{
    int target = 5;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(4);
    vector<vector<int>> soluton = combinationSum2(candidates, target);
    return 1;
}

