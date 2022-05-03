//
// Created by aldlss on 2022/5/3.
//

//937. 重新排列日志文件
//感觉不能说是简单题，写起来有点麻烦，不过学到了stable_sort，小赢
//还有这个cmp函数如果用引用的话可以省不少空间

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),[&](const string &a,const string &b)->bool {//stable_sort学到了
           if(isalpha(a.back()))
           {
               if(isalpha(b.back()))
               {
                   auto ai=a.find(' '),bj=b.find(' ');
                   if(a.size()-ai==b.size()-bj)
                   {
                        for(int i=1;ai+i!=a.size();++i)
                            if(a[i+ai]!=b[i+bj])return a[i+ai]<b[i+bj];
                        for(int i=0;;++i)
                            if(a[i]!=b[i])
                                return a[i]<b[i];
                   }
                   else
                       return a.substr(ai+1)<b.substr(bj+1);//缝！
               }
               else
                   return true;
           }
           else return false;//这里好像直接返回false就行了，是我智障了
        });
        return logs;
    }
};