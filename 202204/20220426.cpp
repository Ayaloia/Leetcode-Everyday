//
// Created by aldlss on 2022/4/26.
//

//883. 三维形体投影面积
//无脑题，按理说三个一起处理会好很多，但是既然你的数据量这么小，那不是随便玩（
//而且我这个用的变量还少，虽然似乎没什么用（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans=0,sum=0;
        for(auto &i:grid)
            for(int &j:i)
                if(j)++sum;
        ans+=sum;
        sum=0;
        for(auto &i:grid)
        {
            for(int &j:i)
                sum=max(sum,j);
            ans+=sum;
            sum=0;
        }
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.size();++j)
                sum=max(sum,grid[j][i]);
            ans+=sum;
            sum=0;
        }
        return ans;
    }
};