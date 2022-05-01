//
// Created by aldlss on 2022/5/2.
//

//591. 标签验证器
//这题还算有点意思，说难也不是难，主要是判断要逻辑
//本来是想着一个个分析的，结果写着写着就变成照着'<'嗯怼了
//算是编写边优化了？跟最初的构想差的还是比较多的

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string code) {
        if(code[0]!='<'||code.back()!='>')return false;
        stack<string>tagName{};
        char q;
        bool endTag=false;
        int tagStart=0;
        auto i=code.find('<');
        string nowTag{};
        do
        {
            q=code[i];
            if(q=='<')
            {
                tagStart=++i;
                q=code[i];
                if(q=='!')
                {
                    if(code.substr(i,8)=="![CDATA[")
                    {
                        auto result=code.find("]]>",i+8);//find_first_of的用法是找字串里的任意一个字符第一次出现的位置，坑
                        if(result==string::npos)return false;
                        i=result+2;
                    }
                    else return false;
                }
                else
                {
                    if(q=='/')
                    {
                        ++tagStart;
                        if(tagName.empty())return false;
                        endTag=true;
                    }
                    auto result=code.find('>',i+1);
                    if(result==string::npos)return false;
                    i=result;//基本上就是处理tag了，这里是'<'
                    nowTag=code.substr(tagStart,i-tagStart);
                    if(nowTag.empty()||nowTag.size()>9)
                        return false;
                    if(!endTag)
                    {
                        for(char ch:nowTag)
                            if(!isupper(ch))
                                return false;
                        tagName.push(nowTag);
                    }
                    else if(nowTag==tagName.top())
                    {
                        endTag=false;
                        tagName.pop();
                    }
                    else return false;
                }
                if(tagName.empty()&&i!=code.size()-1)return false;
            }
        }
        while((i=code.find('<',i))!=string::npos);
        if(!tagName.empty())return false;//居然没考虑到这个
        return true;
    }
};

int main()
{
    Solution a;
    a.isValid({"<A><![CDATA[</A>]]123></A>"});
    return 0;
}