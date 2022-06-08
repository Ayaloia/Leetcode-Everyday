//
// Created by aldlss on 2022/6/8.
//

//1037. 有效的回旋镖
//题目要求不在一条直线才返回true，搞错了
//然后改了这个又忘记改那个，最后就是一些特殊情况又没注意
//我呕呕啊

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[0]==points[1]||points[1]==points[2]||points[0]==points[2])
            return false;
        if(points[0][0]==points[1][0])
            return points[0][0]!=points[2][0];
        double k= static_cast<double>((points[1][1] - points[0][1]))/(points[1][0]-points[0][0]);
        return abs(k*(points[0][0]-points[2][0])-points[0][1]+points[2][1])>=1e-5;
    }
};