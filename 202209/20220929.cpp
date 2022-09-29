//
// Created by aldlss on 2022/9/29.
//

//面试题 01.09. 字符串轮转
//还能这样写，确实惊为天人啊

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
        return (s2+s2).find(s1)!=s2.npos;
//        if(s1.length()==0)return true;
//        auto len=s1.length();
//        auto hash1=hash<string>();
//        for(int i=1;i<=len;++i)
//        {
//            if(hash1(s1.substr(0,i)+"aya")==hash1(s2.substr(len-i)+"aya"))
//            {
//                if(hash1(s1.substr(i)+"aya")==hash1(s2.substr(0,len-i)+"aya"))
//                    return true;
//                else return false;
//            }
//        }
//        return false;
    }
};