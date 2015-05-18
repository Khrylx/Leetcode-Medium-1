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

struct stringIndex{
    string s;
    int index;
};

bool myCompare(stringIndex& s1,stringIndex& s2){
    return s1.s < s2.s;
}

vector<string> anagrams(vector<string>& strs)
{
    vector<string> solutions;
    
    vector<stringIndex> sIndex(strs.size());
    
    for (int i = 0 ; i < strs.size(); i++) {
        sIndex[i].s = strs[i];
        sIndex[i].index = i;
        sort(sIndex[i].s.begin(), sIndex[i].s.end());
//        cout<< sIndex[i].s <<endl;
    }
    
    sort(sIndex.begin(), sIndex.end(), myCompare);
    
    bool find = false;

    for (int i = 1 ; i < sIndex.size(); i++) {
        if (sIndex[i].s == sIndex[i-1].s) {
            if(!find)
                solutions.push_back(strs[sIndex[i-1].index]);
            solutions.push_back(strs[sIndex[i].index]);
            find = true;
        }
        else{
            find = false;
        }
    }
    
    return solutions;
}

int main()
{
    vector<string> strs;
    strs.push_back("tea");
    strs.push_back("and");
    strs.push_back("ate");
    strs.push_back("eat");
    strs.push_back("dan");
    vector<string> solutions = anagrams(strs);
    
    return 1;
}

