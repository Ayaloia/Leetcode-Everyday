//
// Created by aldlss on 2022/5/19.
//

//462. 最少移动次数使数组元素相等 II
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
//        double avg= accumulate(nums.begin(),nums.end(),0)/nums.size();
//        int avgInt=static_cast<int>(avg+0.5);
//        int ans=0;
//        for(int i:nums)
//            ans+=abs(i-avgInt);
//        return ans;
        if(nums.size()<=1)return 0;
        int ans=0;
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        while(1)
        {
            while(nums[left]==nums[left+1])
            {
                ++left;
                if(left>=right)break;
            }

            while(nums[right]==nums[right-1]&&left<right)
                --right;
            if(left>=right)break;
            if(left+1<nums.size()-right)
            {
                ans+=(left+1)*nums[left+1]-nums[left];
                nums[left]=nums[left+1];
            }
            else
            {
                ans+=(nums.size()-right)*(nums[right]-nums[right-1]);
                nums[right]=nums[right-1];
            }
        }
        return ans;
    }
};