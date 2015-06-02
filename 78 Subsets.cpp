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

void subsetHelper(vector<vector<int>>& solutions, vector<int>& curSet, vector<int>& nums, int index)
{
    if (index == nums.size()) {
        solutions.push_back(curSet);
        return;
    }
    
    curSet.push_back(nums[index]);
    subsetHelper(solutions, curSet, nums, index+1);
    curSet.pop_back();
    
    subsetHelper(solutions, curSet, nums, index+1);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> solutions;
    vector<int> curSet;
    
    if (nums.empty()) {
        return solutions;
    }
    
    sort(nums.begin(), nums.end());
    
    subsetHelper(solutions, curSet, nums, 0);
    
    return solutions;
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    
    vector<vector<int>> S = subsets(nums);
    
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    return 1;
}

