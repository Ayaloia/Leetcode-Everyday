//
// Created by aldlss on 2022/5/15.
//

//812. 最大三角形面积

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxx=0;
        for(int i=0;i<points.size();++i)
            for(int j=i+1;j<points.size();++j)
                for(int k=j+1;k<points.size();++k)
                    maxx=max(maxx,abs(points[i][0]*points[j][1]-points[i][0]*points[k][1]+points[j][0]*points[k][1]-points[j][0]*points[i][1]+points[k][0]*points[i][1]-points[k][0]*points[j][1])/2.0);
        return maxx;
    }
};