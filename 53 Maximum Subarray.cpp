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

int maxSubArray(vector<int>& nums)
{
    if (nums.empty())
        return 0;
    
    int max = nums[0];
    int sum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        if (sum > max){
            max = sum;
        }
        
        if (sum < 0) {
            sum = 0;
        }
    }
    
    return max;
}

int main()
{
    int N;
    cin>>N;
    vector<int>  nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
//    nums.push_back(1);
    
    cout<<maxSubArray(nums)<<endl;
    
    return 1;
}

