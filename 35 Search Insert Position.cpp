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

using namespace std;


int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = (int)nums.size();
    if (nums[left] >= target) {
        return left;
    }
    if (nums[right-1] < target) {
        return right;
    }
    
    while (right - left > 1) {
        int newPos = (left+right) / 2;
        if (nums[newPos] == target) {
            return newPos;
        }
        else if(nums[newPos] > target){
            if(nums[newPos-1] < target){
                return newPos;
            }
            else{
                right = newPos;
            }
        }
        else{
            left = newPos;
        }
    }
    
    return -1;
    
}

int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for (int i = 0 ; i < N; i++) {
        cin >> nums[i];
    }

    cout<<"solution = "<<searchInsert(nums,K)<<endl;
    
    return 1;
}

