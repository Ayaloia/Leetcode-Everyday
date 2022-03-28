//
// Created by aldlss on 2022/3/27.
//
/*需要注意的一些坑比较多，其他的还好*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;
        int sum=mean*(n+rolls.size());
        for(int i:rolls)sum-=i;
        int mean1=sum/n;
        if(mean1<=0||mean1>6)return ans;
        if(mean1*n!=sum)
        {
            if(mean1==6)return ans;
            do
            {
                ans.push_back(mean1);
                sum -= mean1;
                --n;
            }
            while((mean1+1)*n!=sum);
            do ans.push_back(mean1+1);
            while(--n);
        }
        else
        {
            do ans.push_back(mean1);
            while (--n);
        }
        return ans;
    }
};