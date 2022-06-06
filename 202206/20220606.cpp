//
// Created by aldlss on 2022/6/6.
//

//732. 我的日程安排表 III
//还是用了map，本来觉得线段树可以写的
//不过似乎越写越变成手撸了，感觉不太对，赶快润了
//以后有时间再琢磨吧，还要复习呢
#include<bits/stdc++.h>
using namespace std;
class MyCalendarThree {
public:
    map<int,int>time;
    MyCalendarThree():time{} {

    }

    int book(int start, int end) {
        ++time[start];
        --time[end];
        int ans=0,sum=0;
        for(auto [idx,val]:time)
        {
            sum+=val;
            ans=max(ans,sum);
        }
        return ans;
    }
};


//不会写还是别写了
//class MyCalendarThree {
//private:
//    struct node
//    {
//        int l,r,ltree,rtree,val,lazy;
//        node()=default;
//        node(int l,int r,int val,int lazy):l(l),r(r),ltree(0),rtree(0),val(val),lazy(lazy){}
//    };
//    vector<node>tree{};
//    int update(int root,int l,int r,int val)
//    {
//        node now=tree[root];
//        int nowl=now.l,nowr=now.r;
//        if(nowl==l&&nowr==r)
//        {
//            now.val+=val;
//            now.lazy+=val;
//            return now.val;
//        }
//        int mid=(nowl+nowr)>>1;
//        if(mid>=r)
//        {
//            if(!now.ltree)
//            {
//                tree.emplace_back(nowl,mid,0,0);
//                now.ltree=tree.size();
//            }
//            return now.val=now.lazy+update(now.ltree,l,r,val);
//        }
//    }
//public:
//    MyCalendarThree(){
//        tree.emplace_back(0,1000000000,0,0);
//    }
//    int book(int start, int end) {
//
//    }
//};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */