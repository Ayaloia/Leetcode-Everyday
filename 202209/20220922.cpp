//
// Created by aldlss on 2022/9/22.
//

//1640. 能否连接形成数组
//写写简单题麻痹下自己，唉

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool ok=false;
        int i=0;
        while(i<arr.size())
        {
            ok=false;
            for(auto &piece:pieces)
            {
                if(arr[i]==piece[0])
                {
                    ok= true;
                    for(int &j:piece)
                    {
                        if(j!=arr[i])
                            return false;
                        ++i;
                    }
                    break;
                }
            }
            if(!ok)return false;
        }
        return true;
    }
};