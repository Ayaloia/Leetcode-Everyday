//
// Created by aldlss on 2022/4/3.
//

//入门题，看代码量，一个二分就秒了……没什么意思

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto mark= upper_bound(letters.begin(),letters.end(),target);
        if(mark==letters.end())return letters[0];
        return *mark;
    }
};