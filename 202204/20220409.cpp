//
// Created by aldlss on 2022/4/9.
//

//有难度，不过想到可以反推之后就好算不少，主要问题还是便界判断
//看了看题解，写的比我清楚多了，主要我这个还是有点面向数据编程的感觉，错了就改- -

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx==tx&&sy==ty)return true;
        while(tx>=sx&&ty>=sy)
        {
            if(tx>ty)
            {
                swap(tx,ty);
                swap(sx,sy);
            }
            if((ty-sy)%tx==0)
            {
                ty=sy;
                if((tx-sx)%ty==0||tx==sx)return true;//这里要仔细思考一下
                else return false;
            }
            else ty%=tx;
        }
        if(sx==tx&&sy==ty)return true;
        return false;
    }
};

int main()
{
    Solution a;
    bool bb=a.reachingPoints(1,1,3,5);
    return 0;
}