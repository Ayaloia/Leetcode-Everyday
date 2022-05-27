//
// Created by aldlss on 2022/5/28.
//

//1021. 删除最外层的括号
//计数，大于1就录入

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s.empty())return {};
        string ans{};
        int count=0;
        for(char& q:s)
        {
            if(q=='(')
            {
                if(++count>1)ans+=q;//这里如果不加大括号似乎会被编译成与起来（？这样效果就不一样了
            }
            else if(count-->1)ans+=q;
        }
        return ans;
    }
};