//
// Created by aldlss on 2022/4/22.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
//        int sum=accumulate(nums.begin(),nums.end(),0);
        int Rsum=0,ans=-0x7FFFFFFF,n=nums.size(),sum=0;
        for(int i=0;i<n;++i)
        {
            Rsum+=i*nums[i];
            sum+=nums[i];//这样写还更慢了呃呃
        }
        ans=max(ans,Rsum);
        for(int i=n-1;i>0;--i)
        {
            Rsum+=sum-nums[i]*n;
            ans=max(ans,Rsum);
        }
        return ans;
    }
};