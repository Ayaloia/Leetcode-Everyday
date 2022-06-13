//
// Created by aldlss on 2022/6/13.
//

//1051. 高度检查器

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>sor{heights};
        sort(sor.begin(), sor.end());
        int ans=0;
        for(int i=0;i<sor.size();++i)
            if(heights[i]!=sor[i])
                ++ans;
        return ans;
    }
};