//
// Created by aldlss on 2022/4/11.
//

//简单题，推一下就出来了，而且这个数据取值范围只有0~8，好小，感觉甚至可以直接打表- -

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int muti(int k)
    {
        int sum=9;
        for(int i=9;i>k;--i)sum*=i;
        return sum;
    }
    int countNumbersWithUniqueDigits(int n) {
        int sum[13];
        memset(sum,0,sizeof(sum));
        sum[0]=1;
        for(int i=1;i<=n;++i)sum[i]=sum[i-1]+muti(10-i);
        return sum[n];
    }
};