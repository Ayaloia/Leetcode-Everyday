//
// Created by aldlss on 2022/7/20.
//

//1260. 二维网格迁移
//写点好方法，省了不少时间，lucky~~

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        k=-k%(n*m);
        if(!k)return grid;
        k+=n*m;
        vector<vector<int>>ans(n,vector<int>(m,0));
        int posi=k/m,posj=k%m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                ans[i][j]=grid[posi][posj];
                if(++posj==m)
                {
                    posj&=0;
                    if(++posi==n)
                        posi&=0;
                }
            }
        return ans;
    }
};