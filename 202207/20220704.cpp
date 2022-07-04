//
// Created by aldlss on 2022/7/4.
//

//1200. 最小绝对差
//简单题，排序秒了

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn=0x3F3F3F3F;
        int del=0;
        vector<vector<int>>ans{};
        for(int i=0;i<arr.size()-1;++i)
        {
            del=arr[i+1]-arr[i];
            if(del==minn)
                ans.emplace_back(initializer_list<int>{arr[i],arr[i+1]});
            else if(del<minn)
            {
                minn=del;
                ans.clear();
                ans={{arr[i],arr[i+1]}};
            }
        }
        return ans;
    }
};