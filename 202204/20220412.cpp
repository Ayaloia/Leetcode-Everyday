//
// Created by aldlss on 2022/4/12.
//

//806. 写字符串需要的行数
//简单题，直接扫过去，鉴定为入门难度

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int nowLen=0,line=1;
        for(char q:s)
        {
            if(nowLen+widths[q-'a']>100)
            {
                ++line;
                nowLen=widths[q-'a'];
            }
            else nowLen+=widths[q-'a'];
        }
        return {line,nowLen};
    }
};