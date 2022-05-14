//
// Created by aldlss on 2022/5/14.
//

//691. 贴纸拼词
//记忆化搜索+状态压缩，我还是挺佩服能想出来这个的
//只能说两个是相辅相成的，这题你不状压就做不了记忆化
//好厉害的题目，学到，可惜也不知道能不能活用啊

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n=target.size();
        vector<int>memory(1<<n,0);
        function<int(int state)>dfs=[&](int state)->int {
            if(state+1==1<<n)return 0;
            if(memory[state])return memory[state];
            int ans=n+1;
            for(string &str:stickers)
            {
                vector<int>num(26);//你妈的，注意初始化列表{}和构造函数()的区别
                for(char &q:str)
                    ++num[q-'a'];
                int nstate=state;
                for(int i=0;i<n;++i)
                {
                    if((!(nstate>>i&1))&&num[target[i]-'a'])
                    {
                        nstate|=1<<i;
                        --num[target[i]-'a'];
                    }
                }
                if(nstate!=state)ans=min(ans,dfs(nstate)+1);
            }
            return memory[state]=ans;
        };
        int ans=dfs(0);
        if(ans<=n)return ans;
        return -1;
    }
};
int main()
{
    Solution a;
    vector<string>te{"with","example","science"};
    a.minStickers(te,"thehat");
    return 0;
}
//        unordered_multiset<char>count{};
//        for(char &q:target)
//            count.insert(q);
//        array<int,30>mapping{};
//        int tot=0,n=stickers.size();
//        vector<int>need{};
//        need.push_back(0);
//        for(auto item:count)
//        {
//            if(!mapping[item-'a'+1])mapping[item-'a'+1]=++tot;
//            need.push_back(count.count(item));
//        }
//        vector<vector<int>>strsCount{stickers.size(),vector<int>(tot+1,0)};
//        for(int i=0;i<n;++i)
//        {
//            string &str=stickers[i];
//            int sum=0;
//            for(char &q:str)
//                if(mapping[q])
//                {
//                    ++strsCount[i][mapping[q]];
//                    ++sum;
//                }
//            strsCount[i][0]=sum;
//        }
//        stable_sort(strsCount.begin(),strsCount.end(),[](const vector<int>&a,const vector<int>&b)->bool {
//            return a[0]<b[0];
//        });
//        while(strsCount.back()[0]==0)strsCount.pop_back();
//        int ans=0;
//        n=strsCount.size();
//        vector<int>memory(n,0);
//        function<int(int k,int used)>dfs=[&](int k,int used)->int {
//            if(k>=n)return 100005;
//            bool ok= true,use= false;
//            int sum=10005;
//            for(int j=k;j<strsCount.size();++j)
//            {
//                for(int i=1;i<=tot;++i)
//                {
//                    if(need[i]>0&&strsCount[k][i])
//                    {
//                        if(!use)
//                        {
//                            use= true;
//                            ++used;
//                        }
//                    }
//                    need[i]-=strsCount[k][i];
//                    if(need[i]>0)
//                    {
//                        ok= false;
//                        if(used==ans)return 100005;
//                    }
//                }
//            }
//
//        };
//    }
//};