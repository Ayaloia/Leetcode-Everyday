//
// Created by aldlss on 2022/7/8.
//

//1217. 玩筹码
//简单题，本来还想着能不能优化一下空间的，然而并不能似乎

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a=0;
        for(int& pos:position)
        {
            if(pos%2)++a;
        }
        return min(a, static_cast<int>((position.size() - a)));
    }
};