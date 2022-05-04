//
// Created by aldlss on 2022/5/4.
//

//1823. 找出游戏的获胜者
//约瑟夫问题，用链表写坑还挺多，尤其是我还用了单向链表，谔谔死了
//数学解挺牛的，果然数学就是厉害啊

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1)return 1;//这个太谔谔了
        return (k+findTheWinner(n-1,k)-1)%n+1;
        /*forward_list<int>people{};
        for(int i=n;i;--i) people.emplace_front(i);
        auto point=people.before_begin();
        decltype(point) mark{};
        int now=1;
        while(true)
        {
            mark=point;
            if(++mark==people.end())point=people.before_begin();//这个end的定义要记得，因为删除后和增加后都要判断，所以放这里偷懒了
            if(now==k)
            {
                people.erase_after(point);
                if(--n==1)
                    return point==people.before_begin()?*(++point):*point;
                now=1;
                continue;
            }
            ++now;
            ++point;
        }*/
    }
};

int main()
{
    Solution a;
    a.findTheWinner(500,414);
    return 0;
}