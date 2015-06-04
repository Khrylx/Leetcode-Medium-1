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

void restoreIpAddressesHelper(vector<string>& solutions,vector<string>& curS,string s)
{
    if ((int)s.length() == 0) {
        
        if (curS.size() != 4) {
            return;
        }
        
        string tmpS = curS[0];
        for (int i = 1; i < curS.size(); i++) {
            tmpS += '.'+curS[i];
        }
        solutions.push_back(tmpS);
        return;
    }
    
    if (curS.size() >= 4) {
        return;
    }

    int N = (int)s.length()-3;
    if ((3-curS.size()) <= N && 3*(3-curS.size()) >= N && s[0]!='0') {
        string tmpS = s.substr(0,3);
        int num = atoi(tmpS.c_str());
        if (num <= 255) {
            string newS = s.substr(3);
            curS.push_back(tmpS);
            restoreIpAddressesHelper(solutions, curS, newS);
            curS.pop_back();
        }
    }
    
    N++;
    
    if ((3-curS.size()) <= N && 3*(3-curS.size()) >= N && s[0]!='0') {
        string newS = s.substr(2);
        curS.push_back(s.substr(0,2));
        restoreIpAddressesHelper(solutions, curS, newS);
        curS.pop_back();
    }
    
    N++;
    
    if ((3-curS.size()) <= N && 3*(3-curS.size()) >= N) {
        string newS = s.substr(1);
        curS.push_back(s.substr(0,1));
        restoreIpAddressesHelper(solutions, curS, newS);
        curS.pop_back();
    }

}

vector<string> restoreIpAddresses(string s)
{
    vector<string> solutions;
    vector<string> curS;
    
    restoreIpAddressesHelper(solutions, curS, s);
    
    return solutions;
}

int main(){
    
    vector<string> set = restoreIpAddresses("19216811");
    return 1;
}



