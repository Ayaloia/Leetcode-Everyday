//
// Created by aldlss on 2022/4/10.
//

//简单题，秒了，不过因为初始化的问题学到了constexpr这种东西，虽然最后没用上，不过又学到了
//不得不说stl还是挺好用的，感觉早该用用了

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string ys[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string tem;
        unordered_set<string>aya;
        for(const string& str:words)
        {
            for(const char& q:str)
            {
                tem+=ys[q-'a'];
            }
            aya.insert(tem);
            tem.clear();
        }
        return aya.size();
    }
};