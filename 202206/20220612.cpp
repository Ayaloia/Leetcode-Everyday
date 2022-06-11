//
// Created by aldlss on 2022/6/12.
//

//890. 查找和替换模式
//简单题了，一个映射一个查重结束了
//感觉当做简单题也是可以的难度

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char>ys{};
        bool vis[26]{};
        vector<string>ans{};
        bool ok= false;
        for(auto &word:words)
        {
            if(word.size()!=pattern.size())continue;
            ok= true;
            ys.clear();
            memset(vis,0,sizeof(vis));
            for(int i=0;i<word.size();++i)
            {
                char q=word[i];
                auto pos=ys.find(q);
                if(pos!=ys.end())
                {
                    if(pos->second!=pattern[i])
                    {
                        ok=false;
                        break;
                    }
                }
                else
                {
                    if(vis[pattern[i]-'a'])
                    {
                        ok=false;
                        break;
                    }
                    ys[q]=pattern[i];
                    vis[pattern[i]-'a']=1;
                }
            }
            if(ok)
                ans.emplace_back(word);
        }
        return ans;
    }
};