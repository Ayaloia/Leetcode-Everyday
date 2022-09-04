//
// Created by aldlss on 2022/9/4.
//

//1582. 二进制矩阵中的特殊位置
//简单题，好久没写了，活动一下脑子

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size(),m=mat[0].size();
        vector<int>nlen(n,0);
        int ok=2;
        for(int i=0;i<n;++i)
        {
            ok=2;
            for(int j=0;j<m;++j)
            {
                if(mat[i][j])
                {
                    if(!--ok)
                    {
                        nlen[i]=1;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<m;++i)
        {
            ok=2;
            for(int j=0;j<n;++j)
            {
                if(mat[j][i])
                {
                    if(--ok==1&&!nlen[j])
                    {
                        ++ans;
                    }
                    else
                    {
                        if(!ok)--ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};