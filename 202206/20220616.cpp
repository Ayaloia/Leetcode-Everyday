//
// Created by aldlss on 2022/6/17.
//

//532. 数组中的 k-diff 数对
//排序双指针嗯造，就不用哈希表

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=1,ans=0;
        while(j<nums.size())
        {
            if(i==j||nums[j]-nums[i]<k)
                ++j;
            else if(nums[j]-nums[i]>k)
                ++i;
            else
            {
                if((!i||nums[i]!=nums[i-1])&&(nums[j]!=nums[j-1]||i==j-1))++ans;
                ++i;
                ++j;
            }
        }
        return ans;
    }
};