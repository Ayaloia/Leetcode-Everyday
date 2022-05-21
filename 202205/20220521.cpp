//
// Created by aldlss on 2022/5/21.
//

//961. 在长度 2N 的数组中找出重复 N 次的元素
//初步考虑用unordered_set，毕竟简单题
//有考虑过用随机，不过感觉有点玄学
//没想到题解还真有用随机的，牛的
//不得不说这个随机每次写都不记得怎么写，但是写起来还是有点有趣的

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
//        unordered_set<int>appear{};
//        for(int &i:nums)
//        {
//            auto item=appear.find(i);
//            if(item!=appear.end())return i;
//            appear.emplace(i);
//        }
//        return -1;
        mt19937 mt{random_device{}()};
        uniform_int_distribution<int>random(0,nums.size()-1);
        while(true)
        {
            int a=random(mt),b=random(mt);
            while(a==b)a=random(mt),b=random(mt);
            if(nums[a]==nums[b])return nums[a];
        }
    }
};