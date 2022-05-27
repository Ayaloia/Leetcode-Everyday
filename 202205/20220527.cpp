//
// Created by aldlss on 2022/5/27.
//

//面试题 17.11. 单词距离
//hash，然后再小暴力一下
//虽然只遍历了一次，但我感觉还是有点暴力（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int pos1=-0x3FFFFFFF,pos2=-0x3FFFFFFF,ans=0x3FFFFFFF;
        auto hash=std::hash<string>{};
        auto hash1=hash(word1),hash2=hash(word2);
        for(int i=0;i<words.size();++i)
        {
            auto nowHash=hash(words[i]);
            if(nowHash==hash1)
            {
                pos1=i;
                ans=min(ans,pos1-pos2);
            }
            else if(nowHash==hash2)
            {
                pos2=i;
                ans=min(ans,pos2-pos1);
            }
        }
        return ans;
    }
};