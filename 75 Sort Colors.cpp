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

void sortColors(vector<int>& nums) {
    int index0 = 0;
    int index2 = (int)nums.size()-1;
    while (nums[index2] == 2) {
        index2--;
    }
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0){
            if (i != index0) {
                nums[i] = 1;
            }
            nums[index0++] = 0;
        }
        else if(nums[i] == 2){
            if (i < index2) {
                nums[i] = 1;
            }
            else{
                break;
            }
            
            if(nums[index2] == 0)          // if '0' was overwritten, place it in the write slot.
                nums[index0++] = 0;
            
            nums[index2--] = 2;
            while (nums[index2] == 2) {    // find next slot for '2'
                index2--;
            }

        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sortColors(nums);
    
    for (int i = 0; i < n; i++) {
        cout << nums[i] <<" ";
    }
   
    
    
    
    return 1;
}

