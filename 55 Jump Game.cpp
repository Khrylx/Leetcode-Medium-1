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

bool canJump(vector<int>& nums)
{
    if (nums.size() <= 1 || nums[0] >= nums.size()-1) {
        return true;
    }
    
    int maxDist = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (i > maxDist) {
            return false;
        }
        
        maxDist = max ( maxDist , i + nums[i]);
        if (maxDist >= nums.size()-1) {
            return true;
        }
    }
    
    
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    
    
    cout<<endl;
    
    
    cout << canJump(nums) << endl;
    
    return 1;
}

