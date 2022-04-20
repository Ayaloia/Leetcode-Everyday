//
// Created by aldlss on 2022/4/21.
//

//824. 山羊拉丁文
//简单题，不多说，没什么难度，看题目这个描述山羊拉丁文感觉像是neta另一个题目的梗啊（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence+=" ";
        string ans{},temp{};
        int mark=1;
        for(char &q:sentence)
        {
            if(mark==1)//是开头吗
            {
                if(q=='a'||q=='e'||q=='u'||q=='i'||q=='o'||q=='A'||q=='E'||q=='U'||q=='I'||q=='O')//还有大写呃呃
                {
                    mark=0;
                    ans+=q;
                }
                else mark=q;//记录首单词
            }
            else if(q==' ')
            {
                if(mark>1)
                    ans+=static_cast<char>(mark);
                ans+="ma";
                temp+='a';
                ans+=temp;
                ans+=' ';
                mark=1;
            }
            else ans+=q;
        }
        ans.pop_back();//之前多加了个空格，记得减回去（
        return ans;
    }
};