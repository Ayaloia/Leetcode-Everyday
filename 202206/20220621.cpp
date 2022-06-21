//
// Created by aldlss on 2022/6/21.
//

//1108. IP 地址无效化

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string ans{};
        for(char &q:address)
        {
            if(q=='.')
                ans.append("[.]");
            else ans+=q;
        }
        return ans;
    }
};