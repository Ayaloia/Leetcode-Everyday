//
// Created by aldlss on 2022/6/25.
//

//剑指 Offer II 091. 粉刷房子
//算是基础的动态规划题，感觉还是挺送的

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>ans(n,vector<int>(3,0));
        constexpr int other[3][2]={{1,2},{0,2},{0,1}};
        for(int i=0;i<3;++i)
            ans[0][i]=costs[0][i];
        for(int i=1;i<n;++i)
            for(int j=0;j<3;++j)
                ans[i][j]=min(ans[i-1][other[j][0]],ans[i-1][other[j][1]])+costs[i][j];
        return min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2]));
    }
};