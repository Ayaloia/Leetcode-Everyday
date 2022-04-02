//
// Created by aldlss on 2022/4/2.
//

//原本以为题解们会有什么高明的解法，结果也是纯纯的分类讨论和嗯模拟啊，我谔谔
//我得说写的时候有些地方还在考虑时间复杂度，不过一想到就这点数据哪里用卡时啊(

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        vector<int>resum;
        bool upper,lower,digit;
        int ans,sum,re,marksum,len=password.length();
        char mark=0;
        upper=lower=digit=re=marksum=sum=ans=0;
        for(char q:password)
        {
            if(islower(q))lower= true;
            else if(isupper(q))upper= true;
            else if(isdigit(q))digit=true;
            if(mark==q)++re;
            else
            {
                if(re>2)resum.push_back(re);
                mark=q;
                re=1;//应该=1的
            }
        }
        if(re>2)resum.push_back(re);
        marksum=lower+upper+digit;
        if(len<6)return max(3-marksum,int(6-len));
        else
        {
            re=0;
            if(len>20)
            {
                int del=len-20;
                re=del;//复用一下
                for(int i:resum)sum+=len-2;
                if(del>=sum)return del+3-marksum;//这里就是可以防止后面一直减不下去循环
                else
                {
                    sum=0;
                    sort(resum.begin(),resum.end(),[](int a,int b)->bool{return a%3<b%3;});
                    while(del)for(int &i:resum)
                    {
                        if(!i)continue;
                        sum=i%3+1;
                        if(del>sum)
                        {
                            if(i<sum)continue;//这里，没想到是会减到负数的，有点面向数据编程了- -//应该放这里才对，我谔谔啊
                            del-=sum;
                            i-=sum;
                        }
                        else
                        {
                            i-=del;
                            del=0;
                            break;
                        }
                    }
                    len=20;
                }
            }
            sum=0;
            for(int i:resum)sum+=i/3;
            return re+max(sum,3-marksum);
        }
    }
};

int main()
{
    Solution a;
    a.strongPasswordChecker("1010101010aaaB10101010");
    return 0;
}