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

string simplifyPath(string path)
{
    string newPath;
    stack<string> S;
    
    int index = 0;
    
    while (index < (int)path.length()) {
    
        int newIndex = (int)path.find_first_of('/',index+1);
        if (newIndex == string::npos) {
            if (index == path.length()-1) {
                break;
            }
            else{
                newIndex = (int)path.length();
            }
        }
        
        string dir = path.substr(index+1,newIndex-index-1);
        index = newIndex;
        
        if (dir == "" || dir == ".") {

            continue;
        }
        else if(dir == ".."){
            if (!S.empty()) {
                S.pop();
            }
        }
        else {
            S.push(dir);
        }
    }
    
    while(!S.empty())
    {
        newPath = "/" + S.top() + newPath;
        S.pop();
        
    }
    if (newPath.empty()) {
        newPath = "/";
    }
    return newPath;
    
}

int main(){
    cout << simplifyPath("/a/./b/../../c/../") <<endl;
    return 1;
}

