//
// Created by aldlss on 2022/4/7.
//

/*一眼拼接调库，不过没想到它还会给字符串长度不一样的，草率了*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;//我寻思也没说长度不一样啊
        s+=s;
        if(s.find(goal)!=s.npos)return true;
        return false;
    }
};