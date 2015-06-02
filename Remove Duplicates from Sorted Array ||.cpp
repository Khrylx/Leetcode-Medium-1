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

int removeDuplicates(vector<int>& nums)
{
    bool flag = true;
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            if (flag) {
                nums[index++] = nums[i];
                flag = false;
            }
        }
        else{
            nums[index++] = nums[i];
            flag =true;
        }
    }
    
    return index;
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    
    cout << removeDuplicates(nums) << endl;
    
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
    
    
    return 1;
}

