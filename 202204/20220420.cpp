//
// Created by aldlss on 2022/4/20.
//

//388. 文件的最长绝对路径
//有点难度，其实不是很难，主要是题目有些地方有点含糊不清
//用vector的空间比stack似乎还更小，不知道为什么，有点玄学

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int>len{0};
//        stack<int>len{};//换个方法试试
        input+="\n";
        int sum=0,ans=0,depth=-1;
        bool file=false;
        for(char &q:input)
        {
            switch(q)
            {
                case '\n':
                    if(file)
                    {
                        ans=max(ans,sum);
                        file=false;
                    }
                    else
                        len.push_back(sum+1);
//                    sum=0;
                    depth=0;
                    break;
                case '\t':
                    if(depth>=0)++depth;
//                    else if(sum)++sum;这个纯属想多了，不用管，他的input还是比较符合的
                    break;
                case '.':
                    file=true;
                default:
                    if(depth>=0)
                    {
                        while(len.size()>depth+1)
                            len.pop_back();
                        depth=-1;
                        sum=len.back();
//                        if(!len.empty())sum=len.back();//如果空了会爆
//                        else sum=0;//按理说我插一个0在最顶端也是可行的，但是这样判断又要改...
                    }
                    ++sum;
                    break;
            }
        }
        return ans;
    }
};
int main()
{
    Solution a;
    int b=a.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    return 0;
}