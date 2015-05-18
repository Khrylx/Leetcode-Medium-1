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

using namespace std;

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& solutions)
{
    if (start == nums.size()-1) {
        solutions.push_back(nums);
    }
    
    for (int i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        permuteHelper(nums, start+1, solutions);
        swap(nums[i], nums[start]);
    }
    
}


vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> solutions;
    
    permuteHelper(nums, 0, solutions);
    
    return solutions;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
//    nums.push_back(1);
//    nums.push_back(4);
    vector<vector<int>> solutions = permute(nums);
    return 1;
}

