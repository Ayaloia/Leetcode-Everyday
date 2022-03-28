//
// Created by aldlss on 2022/3/28.
//

//简单题，只要会位运算就很容易了，主要考虑如何优化更多

class Solution {
public:
    bool hasAlternatingBits(int n) {
        do if(!(n>>1&1)^(n&1))return false;
        while(n>>=1);
        return true;
    }
};