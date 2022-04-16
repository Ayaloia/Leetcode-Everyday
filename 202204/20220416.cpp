//
// Created by aldlss on 2022/4/16.
//

//这题目我不好说，没想到最后是pow函数搞死人，索性自己写了个实现
//断签了……早知道昨天就先抄个答案交上去勒（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNotPrime(long long k,int n)
    {
        for(int i=k/power(n);i<=sqrt(k);++i)
        {
            if(k%i==0&&k/i<power(n))return true;
        }
        return false;
    }
    inline long long power(int n)
    {
        long long sum=1;
        for(int i=1;i<=n;++i)
            sum*=10;
        return sum;
    }
    long long hw(int aim,int k=0,long long sum=0)
    {
        if(aim==k)
        {
            if(isNotPrime(sum,k))return sum;
            return 0;
        }
        for(int i=9;i>=0;--i)
        {
            long long ans=0;
            if(ans=hw(aim,k+1,sum+i*power((aim*2-k)-1)+i*power(k*1.0)))
                return ans;
        }
        return 0;
    }
    int largestPalindrome(int n) {
        if(n==1)return 9;
        return hw(n)%1337;
    }
};

int main()
{
    Solution a;
    a.largestPalindrome(8);
    return 0;
}