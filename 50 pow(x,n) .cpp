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

double myPow(double x, int n)
{
    if (x == 0) {
        return 0;
    }
    
    if (n == 0) {
        return 1;
    }
    
    bool sign = n > 0;
    if(!sign)
        n = -n;
    
    double res = 1;
    double tmpRes = x;
    int radius = 1;
    
    
    while (1) {
        if ((n & radius) != 0) {
            res *= tmpRes;
        }
        if (radius > n >> 1) {
            break;
        }
        
        radius = radius << 1;
        tmpRes *= tmpRes;
    }
    
    return sign ? res : 1/res;
    
    
}

int main()
{
    double x = 8.84372;
    int n = -5;
    cout<< myPow(x, n)-pow(x, n)<<endl;
    
    return 1;
}

