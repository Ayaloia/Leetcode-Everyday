//
// Created by aldlss on 2022/5/13.
//

//面试题 01.05. 一次编辑

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int del=static_cast<int>(first.size()-second.size());
        if(abs(del)>1)return false;
        if(del==0)
        {
            int mark=0;
            for(int i=0;i<first.size();++i)
                if(first[i]!=second[i])
                {
                    ++mark;
                    if(mark>1)return false;
                }
        }
        else
        {
            if(first.size()>second.size())first.swap(second);
            int i=0,j=0,mark=0;
            while(i<first.size()&&j<second.size())
            {
                while(first[i]!=second[j])
                {
                    ++mark;
                    if(mark>1)return false;
                    ++j;
                }
                ++i;
                ++j;
            }
            if(i!=first.size()&&j!=second.size())return false;
        }
        return true;
    }
};