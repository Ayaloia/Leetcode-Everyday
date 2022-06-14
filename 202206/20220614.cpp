//
// Created by aldlss on 2022/6/14.
//

//498. 对角线遍历
//模拟呗，分情况讨论
//层级决定方向，不过基本上就两种
//用我最喜欢的^=1写

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x=0,y=0,m=mat.size()-1,n=mat[0].size()-1,lever=0;
        vector<int>ans{};
        constexpr int dx[2]={1,-1},dy[2]={-1,1};
        while(y!=m||x!=n)
        {
            ans.emplace_back(mat[y][x]);
            if(x==n&&!lever)
            {
                ++y;
                lever^=1;
            }
            else if((y==0&&!lever)||(y==m&&lever))
            {
                ++x;
                lever^=1;
            }
            else if(x==0&&lever)
            {
                ++y;
                lever^=1;
            }
            else
            {
                x+=dx[lever];
                y+=dy[lever];
            }
        }
        ans.emplace_back(mat[m][n]);
        return ans;
    }
};