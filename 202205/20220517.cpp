//
// Created by aldlss on 2022/5/17.
//

//953. 验证外星语词典
//简单题，考虑直接映射了，有点暴力是有点暴力，但是好用
//毕竟是简单题，而且这数据量，我笑了

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char ls[26];
        for(int i=0;i<26;i++)
            ls[order[i]-'a']=i+'a';
        for(auto &str:words)
            for(auto &q:str)
                q=ls[q-'a'];
        for(int i=1;i<words.size();++i)
            if(words[i]<words[i-1])
                return false;
        return true;
    }
};