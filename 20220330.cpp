//
// Created by aldlss on 2022/3/30.
//
#include "bits/stdc++.h"
using namespace std;

/*
绷不住了，打了个模拟结果超时了，竟然是一时半会都没有想到这种set和map的用法，感觉似乎智力下降了不少啊
要说的话，倒是学到了一些c++11的新方法，看起来c++11确实有不少东西，之前oi的时候一直搞的以前那套不太行了
*/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
//        int now=0,ans[100005],work[100005],sum=arrival.size(),ser=0,mark=0,maxx=0;
//        memset(ans,0,sizeof(ans));
//        memset(work,0,sizeof(work));
//        for(int i=0;i<sum;++i,++ser)
//        {
//            if(ser==k)ser=0;
//            mark=ser;
//            now=arrival[i];
//            while(now<work[mark])++mark;
//            if(mark==k)
//            {
//                for(mark=0;mark<ser;++mark)if(now>=work[mark])break;
//                if(mark==ser)continue;
//            }
//            work[mark]=now+load[i];
//            ++ans[mark];
//        }
//        vector<int>solu;
//        for(int i=0;i<k;++i)maxx=max(maxx,ans[i]);
//        for(int i=0;i<k;++i)
//        {
//            if(ans[i]==maxx)solu.push_back(i);
//        }
//        return solu;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>work;
        set<int>free;
        free.clear();
        while(!work.empty())work.pop();
        int sum[100005],now=0,len=arrival.size(),maxx=0;
        memset(sum,0,sizeof(sum));//以前写在全局变量写习惯了，只能说这些写在类里面的函数必须要初始化
        for(int i=0;i<k;++i)free.insert(i);
        for(int i=0;i<len;++i)
        {
            now=arrival[i];
            while(!work.empty()&&work.top().first<=now)
            {
                free.insert(work.top().second);
                work.pop();
            }
            if(free.empty())continue;
            auto mark=free.lower_bound(i%k);
            if(mark==free.end())mark=free.begin();
            work.emplace(now+load[i],*mark);//学到，还有这种方便的东西
            ++sum[*mark];
            free.erase(mark);//呃呃，把这个语句放在前面了，我就说sum++的时候地址怎么会这么怪，你妈
        }
        maxx= *max_element(sum,sum+k);//学到，还有这种好用的东西
        vector<int>ans;
        for(int i=0;i<k;++i)if(maxx==sum[i])ans.push_back(i);
        return ans;//疑似例子一起跑的时候就会出问题，单个单个跑就没事，我暂且蒙古、反转了，没初始化sum
    }
};

int main()
{
    Solution a;
    vector<int>q{1,2,3,4,5},w{5,2,3,3,3};
    a.busiestServers(3,q,w);
    return 0;
}