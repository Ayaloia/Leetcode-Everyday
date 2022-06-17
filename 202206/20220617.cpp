//
// Created by aldlss on 2022/6/17.
//

//1089. 复写零
//正统答案是双指针，看了下，这个最后从后往前的过程有点让我想到背包了

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;++i)
        {
            if(!arr[i])
            {
                arr.pop_back();
                arr.insert(arr.begin()+i,0);
                ++i;
            }
        }
    }
};