//
// Created by aldlss on 2022/5/19.
//

//462. 最少移动次数使数组元素相等 II
//本来想着平均数，后来发现不对
//然后模拟了一下，大概就是排序后左右两边每次选数少的那边推进
//再优化一下过程，就成这样子了
//后来看到他们说中位数，想了想突然就恍然大悟了
//毕竟是每次选数少的一边推进，最后的结果肯定就是两边的个数一样
//那不就是中位数么？！太猛

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
                if(left>=right)return ans;//怪不得break没有用，原来这个就是一个while
            }
            while(nums[right]==nums[right-1])
                --right;
            if(left+1<nums.size()-right)
            {
                ans+=(left+1)*(nums[left+1]-nums[left]);
                nums[left]=nums[left+1];
            }
            else
            {
                ans+=(nums.size()-right)*(nums[right]-nums[right-1]);
                nums[right]=nums[right-1];
            }
        }
    }
};

int main()
{
    Solution a;
    vector<int>aa{1,2};
    a.minMoves2(aa);
    return 0;
}