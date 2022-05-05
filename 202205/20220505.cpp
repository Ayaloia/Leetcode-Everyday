//
// Created by aldlss on 2022/5/5.
//

//713. 乘积小于 K 的子数组
//简单题，没理解清题意就开始想属实浪费了我不少时间

#include "bits/stdc++.h"
using namespace std;
class Solution {
public://你妈，是连续子数组，怪不得我还说有点难度，哭了，不过也只是简单了一点
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,sum=1,ans=0;
        while(r<nums.size())
        {

            while(l<r&&nums[r]*sum>=k)
                sum/=nums[l++];
            if(nums[r]*sum>=k&&l==r)
            {
                l=++r;
                continue;
            }
            ans+=r-l+1;
            sum*=nums[r];
            ++r;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int>b{10,2,5,6};
    a.numSubarrayProductLessThanK(b,100);
    return 0;
}