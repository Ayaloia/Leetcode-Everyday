//
// Created by aldlss on 2022/4/1.
//
#include "bits/stdc++.h"
using namespace std;

//算是比较简单的题，当然我这种方法有点浪费空间，肯定是不合适的
//看到有构造绝对值小的优先队列的，感觉确实有道理，还有一些其他方法属实是没有想到了
//还有有时候会遗漏一些操作，这是不可取的

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int exist[200005],mark=0;
        const int SIZE=100000;
        memset(exist,0,sizeof(exist));
        sort(arr.begin(),arr.end());
        for(int i:arr)++exist[i+SIZE];
        if(exist[0])
        {
            if(exist[SIZE]%2)return false;
            else exist[SIZE]=0;
        }
        for(int i:arr)
        {
            if(exist[i+SIZE])
            {
                if(i<0)
                {
                    mark=(i>>1)+SIZE;
                    if(!(i%2)&&exist[mark])//跪了，逻辑取反优先级竟然这么高
                    {
                        --exist[mark];
                        --exist[i+SIZE];//忘记减掉自己的勒
                    }
                    else return false;
                }
                else
                {
                    mark=(i<<1)+SIZE;
                    if(exist[mark])
                    {
                        --exist[mark];
                        --exist[i+SIZE];//你妈，结果忘把下面的也减了
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<int>aya{1,2,1,-8,8,-4,4,-4,2,-2};
    a.canReorderDoubled(aya);
    return 0;
}