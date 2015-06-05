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


int numTrees(int n)
{
    vector<int> nums(n+1,0);
    
    nums[0] = 1;
    nums[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            nums[i] += nums[j-1]*nums[i-j];
        }
    }
    
    return nums[n];
}


int main(){
    
    cout << numTrees(3) << endl;
    return 1;
}




