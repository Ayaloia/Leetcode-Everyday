//
// Created by aldlss on 2022/3/29.
//

//确实是刚开始还没想到，不过过了一会还是想到使用滑动窗口的办法解了。代码其实写得不是很好看，但是能用就好（

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0,len=answerKey.length();
        int begin=0,end=0,mark=0,sum=0;
        while(end<len)//先做全T的
        {
            if(answerKey[end]=='F')
            {
                ++mark;
                if(mark>k)
                {
                    while(answerKey[begin]!='F')
                    {
                        ++begin;
                        --sum;
                    }
                    ++begin;
                    --sum;
                    --mark;
                }
            }
            ++sum;
            ans=max(sum,ans);
            ++end;
        }
        begin=end=mark=sum=0;
        while(end<len)//再做F的
        {
            if(answerKey[end]=='T')
            {
                ++mark;
                if(mark>k)
                {
                    while(answerKey[begin]!='T')
                    {
                        ++begin;
                        --sum;
                    }
                    ++begin;
                    --sum;
                    --mark;
                }
            }
            ++sum;
            ans=max(sum,ans);
            ++end;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    a.maxConsecutiveAnswers("TTFF",2);
    return 0;
}