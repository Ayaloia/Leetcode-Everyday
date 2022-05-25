//
// Created by aldlss on 2022/5/25.
//

//467. 环绕字符串中唯一的子字符串
//呃呃，之前没看准给的字符串是26个字母顺序轮流的
//然后以为很难，后来一看题解才发现= =
//而且我看标签还动态规划呢，给我唬得一愣一愣的
//结果看题解才发现原来这也是动态规划，这真的是吗= =
//不过仔细想想，也是有一些精妙的地方的罢

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size()==1)return 1;
        array<int,26>maxx{};
        p=" "+p;
        int count=0;
        for(int i=1;i<p.size();++i)
        {
            if(p[i]!=p[i-1]+1&&p[i-1]-p[i]!=25)
                count=1;
            else
                ++count;
            maxx[p[i]-'a']=max(maxx[p[i]-'a'],count);
        }
        count=0;
        for(int &val:maxx)
            count+=val;
        return count;
    }
};