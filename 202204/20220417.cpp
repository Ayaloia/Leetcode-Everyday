//
// Created by aldlss on 2022/4/17.
//

//简单题，不过计数这里我觉得能有更快一点的写法，不过觉得复杂度还可以就没管了（
//因为太相信题目，还被坑了一波（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>bans;
        unordered_multiset<string>nums;
        string ans{};
        for(string &str:banned)
        {
            transform(str.begin(),str.end(),str.begin(),::tolower);
            bans.insert(str);
        }
        string mark{};
        int maxx=0,ma=0;
        paragraph+=".";//明明说是段落，结果有时候连句号都没有，我谔谔
        for(int i=0,start=0;i<paragraph.length();++i)
        {
            if(!isalpha(paragraph[i]))
            {
                mark=paragraph.substr(start,i-start);
                transform(mark.begin(),mark.end(),mark.begin(),::tolower);
                if(!mark.empty()&&bans.find(mark)==bans.end())
                {
                    nums.insert(mark);
                    ma=nums.count(mark);
                    if(ma>maxx)
                    {
                        ans=mark;
                        maxx=ma;
                    }
                }
                start=i+1;
            }
        }
        return ans;
    }
};