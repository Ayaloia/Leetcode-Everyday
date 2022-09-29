//
// Created by aldlss on 2022/9/24.
//

//1652. 拆炸弹

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0)return ans;
        int len=code.size();
        for(int i=1;i<len;++i)
            code[i]+=code[i-1];
        if(k>0)for(int i=0;i<len;++i)
        {
            if(i+k>=len)
                ans[i]=code[len-1]-code[i]+code[i+k-len];
            else
                ans[i]=code[i+k]-code[i];
        }
        else
        {
            ans[0]=code[len-1]-code[len-1+k];
            for(int i=1;i<len;++i)
            {
                if(i-1+k<0)
                    ans[i]=code[i-1]+code[len-1]-code[len-1+i+k];
                else
                    ans[i]=code[i-1]-code[i-1+k];
            }
        }
        return ans;
    }
};