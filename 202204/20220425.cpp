//
// Created by aldlss on 2022/4/25.
//

//398. 随机数索引
//可以是简单题，但是随机这块确实还是缺少练习
//这个水塘抽样的算法好厉害，怎么想得出来的，跪了

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*unordered_multimap<int,int>aya;
    mt19937 mt{random_device{}()};
    Solution(vector<int>& nums):aya{} {
        for(int i=0;i<nums.size();++i)
            aya.insert(make_pair(nums[i],i));
    }
    int pick(int target) {
        int num=aya.count(target);
        auto result=aya.find(target);
        num=uniform_int_distribution<>(0,num-1)(mt);
        for(int i=0;i<num;++i)++result;
        return result->second;
    }*/
    vector<int>&nums;
    mt19937 mt{random_device{}()};//这个初始化有点抽象的
public:
    Solution(vector<int>& nums):nums(nums) {}
    int pick(int target) {
        int ans,conut=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==target)
            {
                ++conut;
                if(uniform_int_distribution<>(1,conut)(mt)==1)//这个也有点难记
                    ans=i;//水塘抽样惊为天人
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */