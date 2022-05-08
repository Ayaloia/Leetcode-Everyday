//
// Created by aldlss on 2022/5/8.
//

//442. 数组中重复的数据
//一直以为是异或相关，还想了好久
//虽然看到了数值范围的限制，但是没怎么注意
//一看评论发现竟然还有这种巧办法，跪了

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans{};
        for(int &i:nums)
        {
            if(nums[abs(i)-1]>0)
                nums[abs(i)-1]*=-1;
            else
                ans.push_back(abs(i));
        }
        return ans;
    }
};