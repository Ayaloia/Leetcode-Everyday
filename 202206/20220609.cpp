//
// Created by aldlss on 2022/6/9.
//

//497. 非重叠矩形中的随机点
//加权随机概率确实不好搞，结果想了想只能这样整
//面积总和随机，然后找是哪个矩形的面积
//没想到官解似乎也是这样写的，绷不住了

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>rect;
    vector<int>part;
    int sum;
    mt19937 mt{random_device{}()};
    Solution(vector<vector<int>>& rects):rect(rects),part{},sum(0) {
        part.emplace_back(0);
        for(auto& vec:rect)
        {
            vec[2]-=vec[0]-1;
            vec[3]-=vec[1]-1;
            sum+=(vec[2]*vec[3]);
            part.emplace_back(sum);//储存前缀和，便于二分查找
        }

    }
    vector<int> pick() {
        uniform_int_distribution<int>uni(1,sum);
        int ran=uni(mt);
        int l=0,r=part.size()-2;
        while(true)
        {
            int mid=(l+r)>>1;
            if(part[mid]<ran&&ran<=part[mid+1])
            {
                l=mid;
                break;
            }
            if(part[mid]>=ran)
                r=mid-1;
            else
                l=mid+1;
        }
        ran-=part[l]+1;
        return {rect[l][0]+ran%rect[l][2],rect[l][1]+ran/rect[l][2]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */