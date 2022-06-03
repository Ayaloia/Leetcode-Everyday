//
// Created by aldlss on 2022/6/3.
//

//829. 连续整数求和
//数论题，累了，智力跟不上

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=1,i;
        function<bool(int l,int r)>f=[&](int l,int r)
        {
            if(l>r)
                return false;
            int mid=((r-l)>>1)+l;
            long long sum=static_cast<long long>(mid-i+1)*(mid+i)/2;
            if(sum==n)return true;
            if(sum<n)return f(mid+1,r);
            return f(l,mid-1);
        };
        for(i=1;i<=n>>1;++i)
        {
            if(f(i+1,(n>>1)+1))
                ans++;
        }
        return ans;
    }
};