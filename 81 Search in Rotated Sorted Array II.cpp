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

bool search(vector<int>& nums, int target)
{
    
    if (nums[0] == target || nums.back() == target) {
        return true;
    }
    
    int left = 0;
    int right = (int)nums.size()-1;
    
    while (right - left > 1) {
        //bool sorted = nums[left] < nums[right];
        
        int newPos = (left + right)/2;
        if (nums[newPos] == target) {
            return true;
        }
        else if(nums[newPos] > target){
            if (nums[newPos] == nums[left] && nums[newPos] == nums[right]) {
                int posRecord = newPos;
                while (newPos < right && nums[newPos] == nums[left]) {
                    newPos++;
                }
                if (newPos == right) {
                    right = posRecord;
                }
                else {
                    left = newPos-1;
                }
            }
            else{
                if (nums[newPos] >= nums[left] && nums[left] > target) {
                    left = newPos;
                }
                else{
                    right = newPos;
                }
            }
            
        }
        else{
            if (nums[newPos] == nums[left] && nums[newPos] == nums[right]) {
                int posRecord = newPos;
                while (newPos > left && nums[newPos] == nums[right]) {
                    newPos--;
                }
                if (newPos == left) {
                    left = posRecord;
                }
                else{
                    right = newPos+1;
                }
            }
            else{
                if (nums[newPos] <= nums[right] && nums[right] < target) {
                    right = newPos;
                }
                else{
                    left = newPos;
                }
            }
        }
        
    }
    
    return false;
};

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    
    cout << search(nums,3) << endl;

    
    
    return 1;
}

