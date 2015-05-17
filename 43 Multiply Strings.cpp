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

using namespace std;

string multiply(string num1, string num2)
{
    string res;
    if (num1[0] == '0' || num2[0] == '0') {
        return "0";
    }
    res.resize(num1.length()+num2.length(), '0');


    int N = (int)res.length();
    int N1 = (int)num1.length();
    int N2 = (int)num2.length();

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            int mulRes = (num1[N1-1-i]-'0')*(num2[N2-1-j]-'0') + res[N-1-i-j]-'0';
            res[N-1-i-j] = mulRes % 10 + '0';
            res[N-2-i-j] += mulRes / 10;
            int index = N-i-j-2;
            while (index >=0 && res[index] > '9') {
                res[index] -= 10;
                res[--index] += 1;
            }
        }
    }
    if (res[0]=='0' && res.length()>1) {
        res.erase(res.begin());
    }
    cout<<res<<endl;
    return res;
}

int main()
{
    string num1 = "123";
    string num2 = "123";
    int num3 = atoi(num1.c_str());
    int num4 = atoi(num2.c_str());
    cout << atoi(multiply(num1, num2).c_str()) - num3*num4 <<endl;
    return 1;
}

