//
// Created by aldlss on 2022/7/3.
//

//556. 下一个更大元素 III
//要判断会不会超int，结果最简单的办法还是用longlong啊

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>pl{};
        constexpr int intt=2147483647;
        while(n)
        {
            pl.emplace_back(n%10);
            n/=10;
        }
        for(int i=0;i<pl.size()>>1;++i)
        {
            swap(pl[i],pl[pl.size()-i-1]);
        }
        bool ok=next_permutation(pl.begin(),pl.end());
        if(!ok)return -1;
        if(pl.size()==10&&pl.front()>2)return -1;
        long long ans=0;
        for(int i=0;i<pl.size();++i)
        {
            ans*=10;
            ans+=pl[i];
        }
        return ans>intt?-1:ans;
    }
};