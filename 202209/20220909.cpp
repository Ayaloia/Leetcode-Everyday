//
// Created by aldlss on 2022/9/9.
//

//1598. 文件夹操作日志搜集器
//简单题，我的智商和水平现在只能做这种题复建力

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(auto &s:logs)
        {
            if(s=="../")
            {
//                --level;
                if(level>0)--level;
            }
            else if(s!="./")++level;
        }
        return level;
    }
};