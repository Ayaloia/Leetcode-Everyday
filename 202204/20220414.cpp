//
// Created by aldlss on 2022/4/14.
//

//1672. 最富有客户的资产总量
//简单题，为了多用stl的库又学习了一下，不过又担心stl的效率问题
//只能说c++真麻烦啊……

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto &vec:accounts)
        {
            ans=max(ans,accumulate(vec.begin(),vec.end(),0));
        }
        return ans;
    }
};