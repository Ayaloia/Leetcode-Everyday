//
// Created by aldlss on 2022/4/18.
//

//不简单，如果只是用递归的话确实是一下秒了，但是如果不能用递归还是很难想的
//想了好久（指二十分钟）也没怎么想出来，想着还要写作业，于是只好参考了一下
//不得不说，真的是惊为天人，感觉就像是，有些地方感觉有点巧合甚至有些牵强
//但确实这个代码如此的贴合在一起了，而且还能完美地工作，太猛

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//    void sol(int sum,int n,vector<int>&ans)
//    {
//        if(sum>n)return;
//        ans.push_back(sum);
//        for(int i=0;i<=9;++i)sol(sum*10+i,n,ans);
//    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans(n);
        int sum=1;
        for(int i=0;i<n;++i)
        {
            ans[i]=sum;
            if(sum*10<=n)
                sum*=10;
            else
            {
                while(sum%10==9||sum+1>n)
                    sum/=10;
                ++sum;
            }
        }
        return ans;
    }
};