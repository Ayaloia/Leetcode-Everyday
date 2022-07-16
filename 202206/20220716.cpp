//
// Created by aldlss on 2022/7/16.
//

//剑指 Offer II 041. 滑动窗口的平均值
//猪瘪题，还是别思考太多

#include<bits/stdc++.h>
using namespace std;
class MovingAverage {
public:
    int num;
    double sum;
    vector<int>nums;
    /** Initialize your data structure here. */
    MovingAverage(int size):num(size),sum(0),nums{} {

    }

    double next(int val) {
        nums.emplace_back(val);
        sum+=val;
        if(nums.size()>num)
        {
            sum-=nums[0];
            nums.erase(nums.begin());
        }
        return sum/nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */