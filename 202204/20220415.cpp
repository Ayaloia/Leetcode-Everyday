//
// Created by aldlss on 2022/4/15.
//

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
        NestedInteger ans,*now=&ans;
        int sum=0,flag=1;
        if(s.empty())return {};
        if(s[0]!='[')return {stoi(s)};
        if(s.length()<=2)return {};
        for(char q:s)
        {
            if(q>='0'&&q<='9')
            {
                sum*=10;
                sum+=q-'0';
            }
            else if(q=='-')
            {
                flag=-1;
            }
//            else if(q==']'||q==',')
//            {
//                if(sum)
//                {
//                    NestedInteger *mark=new NestedInteger(sum*flag);
//                    now->add(*mark);
//                    flag=1;
//                    sum=0;
//                }
//                if(q==']')
//                {
//                    level.pop_back();
//                    now=level.back();
//                }
//            }
            else if(q=='[')
            {
                ans.add(deserialize(s.substr()))
            }
        }
        if(sum)
        {
            now->setInteger(sum*flag);
            flag=1;
            sum=0;
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