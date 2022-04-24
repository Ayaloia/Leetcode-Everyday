//
// Created by aldlss on 2022/4/24.
//

//868. 二进制间距
//简单题，随便解决，但我还是不明白为什么我会比别人的多点空间

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int count=-100,ans=0;
        while(n)
        {
            if(n&1)
            {
                ans=max(ans,count);
                count=0;
            }
            ++count;
            n>>=1;
        }
        return ans;
    }
};