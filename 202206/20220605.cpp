//
// Created by aldlss on 2022/6/5.
//

//478. 在圆内随机生成点
//本来以为是爽爽随机题，没想到是概率论哈人题

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double r,x,y;
    mt19937 mt{random_device{}()};
    uniform_real_distribution<double>dis;
    uniform_real_distribution<double>rd;
    Solution(double radius, double x_center, double y_center)
        :r(radius),x(x_center),y(y_center),dis(0, acos(-1)*2),rd(0,r*r) {
    }

    vector<double> randPoint() {
        double temp=dis(mt),temp1=sqrt(rd(mt));
        return {x+temp1*cos(temp),y+temp1*sin(temp)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */