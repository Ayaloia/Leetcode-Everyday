//
// Created by aldlss on 2022/4/19.
//

//简单题，不过纠结复杂度纠结魔怔了，连判断的用时都考虑进去了
//结果确实有点慢了，不过只能说这种情况应该都是差不多的了

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int start=-1;
        vector<int>ans(s.length());
        for(int i=0;i<s.length();++i)
        {
            if(start>=0)ans[i]=i-start;
            else ans[i]=0x3F3F3F3F;
            if(s[i]==c)
            {
                for(int j=i;j>start;--j)
                {
                    ans[j]=min(i-j,ans[j]);
                }
                start=i;
            }
        }
        return ans;
    }
};