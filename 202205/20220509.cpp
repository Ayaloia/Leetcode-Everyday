//
// Created by aldlss on 2022/5/9.
//

//942. 增减字符串匹配
//简单题，好像如果提前设置vector长度的话时空表现都会好一点
//估计是push_back的时候比较需要时间
//然后扩展的时候倍增又比较要空间吧（？

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans(static_cast<int>(s.size())+1);
        int l=0,r=s.size();
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='I')ans[i]=l++;
            else ans[i]=r--;
        }
        ans[s.size()]=r;
        return ans;
    }
};