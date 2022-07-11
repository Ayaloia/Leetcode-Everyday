//
// Created by aldlss on 2022/7/12.
//

//1252. 奇数值单元格的数目

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>msum(m,0),nsum(n,0);
        for(auto& num:indices)
        {
            ++msum[num[0]];
            ++nsum[num[1]];
        }
        int ans=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if((msum[i]+nsum[j])%2)
                    ++ans;
        return ans;
    }
};