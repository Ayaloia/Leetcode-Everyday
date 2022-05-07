//
// Created by aldlss on 2022/5/7.
//

//433. 最小基因变化
//想到比较多种方法，确实也想到了双向bfs
//不过这题目数据就呵呵了，直接bfs也是能解的，感觉就像图论求最短步数一样
//不过居然还能用A*！？这我是没想到的

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        function<bool(string& a,string &b)>isChange=[](string &a,string &b)->bool {
            int sum=0;
            for(int i=0;i<a.size();++i)
                if(a[i]!=b[i])
                {
                    ++sum;
                    if(sum>1)
                        return false;
                }
            if(sum==1)return true;
            return false;
        };
        queue<pair<string,int>>changes{};
        changes.emplace(start,0);
        while(!changes.empty())
        {
            auto now=changes.front();
            if(now.second>bank.size())return -1;//循环搞我
            changes.pop();
            for(string avai:bank)
            {
                if(isChange(now.first,avai))
                {
                    if(avai==end)return now.second+1;
                    changes.emplace(avai,now.second+1);
                }
            }
        }
        return -1;
    }
};