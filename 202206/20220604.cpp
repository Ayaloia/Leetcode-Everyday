//
// Created by aldlss on 2022/6/4.
//

//929. 独特的电子邮件地址
//move快乐题

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>mail{};
        for(auto& str:emails)
        {
            string now{};
            for(char& q:str)
            {
                if(q=='.')continue;
                if(q=='+'||q=='@')
                {
                    mail.emplace(std::move(now.append(str.substr(str.find('@')))));//卧槽什么大嵌套
                    break;
                }
                now+=q;
            }
        }
        return mail.size();
    }
};