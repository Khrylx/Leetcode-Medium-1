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

//int numDecodingsHelper(string s)
//{
//    int res = 0;
//    
//    if (s.length() == 0) {
//        return 0;
//    }
//    
//    if (s.length() > 1 && (s[0] == '1' || (s[0] == '2' && s[1] <= '6') ) ) {
//        int res1 = numDecodingsHelper(s.substr(1), unmatch);
//    }
//    
//}

int numDecodings(string s)
{
    int N = (int)s.length();
    
    if(N == 0)
        return 0;
    
    if (s[0] == '0') {
        return 0;
    }
    
    vector<int> num(N);
    
    num[0] = 1;
    num[1] = 1;
    
    for (int i = 2; i <= N; i++) {
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6') ) {
            if(s[i-1] == '0')
                num[i] = num[i-2];
            else
                num[i] = num[i-1]+num[i-2];
        }
        else if (s[i-1] == '0'){
            return 0;
        }
        else{
            num[i] = num[i-1];
        }
    }

    return num[N];
}

int main(){
    
    cout << numDecodings("0") << endl;
    
    return 1;
}



