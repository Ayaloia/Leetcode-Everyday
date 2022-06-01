//
// Created by aldlss on 2022/6/1.
//

//473. 火柴拼正方形
//本来以为递归会超时，确实超时了
//结果剪枝优化了一下居然就过了（？
//再排序一下这时间直接就几毫秒了！？
//看到是状压dp就感觉很佩服了，感觉似乎状压要么和dp要么和记忆化结合啊
//居然还有模拟退火解法，好怀念

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4)
            return false;
        int sum= accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0)return false;
        sum/=4;
        vector<int>eachSum(4,0);
        sort(matchsticks.begin(), matchsticks.end(),greater<>());//确实应该会快点，再前面先剪枝了
        function<bool(int k)>f=[&](int k=0)->bool{
            if(k==matchsticks.size())
            {
                for(int i=0;i<=3;++i)
                    if(eachSum[i]!=sum)
                        return false;
                return true;
            }
            int last=-1;
            for(int i=0;i<=3;++i)
            {
                if(last==eachSum[i])
                    continue;//剪枝优化一下
                if(eachSum[i]+matchsticks[k]<=sum)
                {
                    eachSum[i]+=matchsticks[k];
                    if(f(k+1))
                        return true;
                    eachSum[i]-=matchsticks[k];
                    last=eachSum[i];
                }
            }
            return false;
        };
        return f(0);
    }
};