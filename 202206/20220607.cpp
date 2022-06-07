//
// Created by aldlss on 2022/6/7.
//

//875. 爱吃香蕉的珂珂
//二分答案，秒了，可惜玩乐浪费了不少时间
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx= *max_element(piles.begin(), piles.end());
        auto pd=[&](int mid)->bool{
            int sum=0;
            for(int &i:piles)
            {
                sum+=i/mid;
                if(i%mid)++sum;
                if(sum>h)return false;
            }
            return true;
        };
        int ans=0;
        function<void(int l,int r)>f=[&](int l,int r)->void {
            if(l>r)return;
            int mid=(l+r)>>1;
            if(pd(mid))
            {
                ans=mid;
                return f(l,mid-1);
            }
            return f(mid+1,r);
        };
        f(1,maxx);
        return ans;
    }
};