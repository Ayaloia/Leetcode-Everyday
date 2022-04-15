//
// Created by aldlss on 2022/4/15.
//

//题目有点含糊不清，本来今天就没什么时间，结果这题目阅读理解我也不太会
//结果最后还是理解错了，看了看别人的代码，属实惊为天人，只能膜拜了……

#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector <NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
        if(s.empty())return {};
        if(s[0]!='[')return {stoi(s)};
        if(s.length()<=2)return {};
        int start=1,cnt=0;
        for(int i=1;i<s.length();++i)
        {
            if(!cnt&&(s[i]==','||i==s.length()-1))
            {
                ans.add(deserialize(s.substr(start,i-start)));
                start=i+1;
            }
            if(s[i]=='[')
                ++cnt;
            else if(s[i]==']')
                --cnt;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    a.deserialize("[123,[456,[789]],[111,123]]");
    return 0;
}