//
// Created by aldlss on 2022/7/7.
//

//648. 单词替换
//stl用久了，已经变成只会用哈希表和映射的样子了
//Tire确实也可以，不过已经开始懒得写了
//虽然这时空复杂度已经快爆掉了，不过算了，就这样吧

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>dicts{};
        for(auto& dict:dictionary)
            dicts.emplace(dict);
        string ans{};
        sentence+=' ';
        bool ok= false;
        int last=0;
        for(auto i=sentence.find(' ',last);i!=sentence.npos;last=i+1,i=sentence.find(' ',last))
        {
            ok= false;
            for(int j=last;j<i;++j)
            {
                if(dicts.find(sentence.substr(last,j-last+1))!=dicts.end())
                {
                    ans.append(sentence.substr(last,j-last+1)+' ');
                    ok= true;
                    break;
                }
            }
            if(!ok)
                ans.append(sentence.substr(last,i-last)+' ');
        }
        ans.pop_back();
        return ans;
    }
};