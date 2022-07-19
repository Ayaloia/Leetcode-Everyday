//
// Created by aldlss on 2022/7/18.
//

//565. 数组嵌套
//本来以为会有环，然后还会有进入环的单向边
//后来发现没有，题目顿时简单了许多
//然后发现甚至不用输出最长环的路径
//又省去了许多，最终感觉是简化了不少

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxx=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>=0)
            {
                int j=i,sum=0;
                do
                {
                    nums[j]=-nums[j]-1;
                    j=-nums[j]-1;
                    ++sum;
                }
                while(j!=i);
                maxx=max(sum,maxx);
            }
        }
        return maxx;
    }
};