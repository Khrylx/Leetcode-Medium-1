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
    
    int count = 1;
    index++;
    while (index < nums.size() && nums[index] == nums[index-1]) {
        index++;
        count++;
    }
    for (int i = 0; i <= count; i++) {
        for (int k = 1; k <= i; k++) {
            curSet.push_back(nums[index-1]);
        }
        
        subsetHelper(solutions, curSet, nums, index);
        
        for (int k = 1; k <= i; k++) {
            curSet.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
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
    
    vector<vector<int>> S = subsetsWithDup(nums);
    
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    return 1;
}



