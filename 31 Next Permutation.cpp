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


void nextPermutation(vector<int>& nums)
{
    int i = (int)nums.size()-1;
    for ( ; i > 0; i--) {
        if (nums[i-1] < nums[i]) {
            break;
        }
    }
    
    if (i>0) {
        int j;
        for (j = i+1; j < nums.size(); j++) {
            if (nums[j] <= nums[i-1]) {
                break;
            }
        }
        int tmp = nums[j-1];
        nums[j-1] = nums[i-1];
        nums[i-1] = tmp;
    }
    
    int left = i;
    int right = (int)nums.size()-1;
    
    while (left < right) {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }

    
}

int main()
{
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0 ; i < N; i++) {
        cin >> nums[i];
    }

    nextPermutation(nums);
    
    return 1;
}

