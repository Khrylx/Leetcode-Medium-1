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


vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> solution(2);
    
    int left = 0;
    int right = (int) nums.size()-1;
    int newPos = -1;
    
    if (nums[left] == target) {
        newPos = left;
    }
    else if (nums[right] == target)
    {
        newPos = right;
    }
    else {
        bool find = false;
        while (right-left>1) {
            newPos = (left+right)/2;
            if (nums[newPos] == target) {
                find = true;
                break;
            }
            else if(nums[newPos]>target){
                right = newPos;
            }
            else{
                left = newPos;
            }
        }
        if (!find) {
            solution[0] = -1;
            solution[1] = -1;
            return solution;
        }
    }
    
    int newPosRecord = newPos;
    
    if(nums[left] == target){
        solution[0] = left;
    }
    else{
        int newLeft = left+1;
        int newRight = newPosRecord;
        if (nums[newLeft] == target && nums[newLeft-1] < target ) {
            solution[0] = newLeft;
        }
        else if (nums[newRight] == target && nums[newRight-1] < target ) {
            solution[0] = newRight;
        }
        else{
            while (newRight - newLeft > 1) {
                newPos = (newRight + newLeft)/2;
                if (nums[newPos] == target) {
                    if (nums[newPos-1] < target) {
                        solution[0] = newPos;
                        break;
                    }
                    else{
                        newRight = newPos;
                    }
                }
                else{
                    newLeft = newPos;
                }
            }
        }
        
    }
    
    if (nums[right] == target) {
        solution[1] = right;
    }
    else{
        int newLeft = newPosRecord;
        int newRight = right-1;
        if (nums[newLeft] == target && nums[newLeft+1] > target) {
            solution[1] = newLeft;
        }
        else if (nums[newRight] == target && nums[newRight+1] > target ) {
            solution[1] = newRight;
        }
        else{
            while (newRight - newLeft > 1) {
                newPos = (newRight + newLeft)/2;
                if (nums[newPos] == target) {
                    if (nums[newPos+1] > target) {
                        solution[1] = newPos;
                        break;
                    }
                    else{
                        newLeft = newPos;
                    }
                }
                else{
                    newRight = newPos;
                }
            }
        }
    }
    
    return solution;
    
}
int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for (int i = 0 ; i < N; i++) {
        cin >> nums[i];
    }

    vector<int> solution = searchRange(nums,K);
    
    return 1;
}

