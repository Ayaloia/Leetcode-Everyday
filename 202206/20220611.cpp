//
// Created by aldlss on 2022/6/11.
//

//926. 将字符串翻转到单调递增
//类似前缀和吧，一个个分割点判定过去
//然后求左边1和右边0的和，然后求最小值

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        vector<int>sum0{0},sum1(s.size()+1,0);
        for(char &q:s)
        {
            if(q=='1')
                sum0.emplace_back(sum0.back()+1);
            else
                sum0.emplace_back(sum0.back());
        }
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]=='0')
                sum1[i]=sum1[i+1]+1;
            else
                sum1[i]=sum1[i+1];
        }
        int ans=0x3F3F3F3F;
        for(int i=0;i<=s.size();i++)
            ans=min(ans,sum0[i]+sum1[i]);
        return ans;
    }
};