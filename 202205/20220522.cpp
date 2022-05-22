//
// Created by aldlss on 2022/5/22.
//

//464. 我能赢吗
//博弈论，本来看到博弈论就麻了，觉得有点难度了
//不过就偷看了一眼用的算法，看到用记忆化搜索和状态压缩
//突然就有点想法了，因为之前也写过用状压和记忆化写的题，记忆还比较深刻
//这题的必胜态和必输态也是令人感叹，总之你有一个别人必输的走法就是必胜的，没有就是必输的
//所以想下来似乎胜负就是可以确定的，于是就这样写下来也竟然就写出来了
//不过特殊条件判断有点恶心，为要求值为0就不说了，这所有总和还会达不到要求值是闹哪样啊

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(!desiredTotal)return true;
        if(((1+maxChoosableInteger)*maxChoosableInteger)>>1<desiredTotal)return false;
        vector<int>memory((1<<maxChoosableInteger));
        function<int(int,int)>f=[&](int state,int sum)->int{//返回1则为当前的人最终会赢,-1为会输
            if(memory[state])return memory[state];
            if(sum>=desiredTotal)return -1;
            for(int i=0;i<maxChoosableInteger;++i)
            {
                int mask=1<<i;
                if(!(mask&state))
                {
                    if(f(mask|state,sum+i+1)==-1)
                    {
                        memory[state]=1;
                        return 1;
                    }
                }
            }
            return -1;
        };
        if(f(0,0)==1)return true;
        else return false;
    }
};

int main()
{
    Solution a;
    a.canIWin(3,4);
    return 0;
}