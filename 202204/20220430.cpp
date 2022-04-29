//
// Created by aldlss on 2022/4/29.
//

//908. 最小差值 I
//简单题，想想就懂了，还提前写了先（

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxx=0,minn=0x3F3F3F3F;
        for(int i:nums)
        {
            maxx=max(maxx,i);
            minn=min(minn,i);
        }
        if(maxx-k<=minn+k)return 0;
        else return maxx-minn-2*k;
    }
};