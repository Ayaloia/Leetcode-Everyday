//
// Created by aldlss on 2022/5/20.
//

//436. 寻找右区间
//我去，本来以为用unordered_map记忆化一下能快点的
//结果发现反而慢了，是没吸氧的原因吗（
//也可能是相同的数据太少了，导致记忆化效果不明显

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return {-1};
        vector<int>ans(intervals.size());
        for(int i=0;i<intervals.size();++i)
            intervals[i].emplace_back(i);
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b)->bool {return a[0]<b[0];});
//        unordered_map<int,int>memory{};
        int mark=-1;
        function<void(int,int,int&)>ef=[&](int l,int r,int &target)->void {
            if(l>r)return;
            int mid=(l+r)>>1;
            if(intervals[mid][0]>=target)
            {
                mark=intervals[mid][2];//还是得用之前的序号
                return ef(l,mid-1,target);
            }
            return ef(mid+1,r,target);
        };
        for(auto &item:intervals)
        {
//            auto result=memory.find(item[1]);
//            if(result!=memory.end())
//            {
//                ans[item[2]]=result->second;
//                continue;
//            }
            mark=-1;
            ef(0,intervals.size()-1,item[1]);
//            memory.emplace(item[1],mark);
            ans[item[2]]=mark;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>>e{{3,4},{2,3},{1,2}};
    a.findRightInterval(e);
    return 0;
}