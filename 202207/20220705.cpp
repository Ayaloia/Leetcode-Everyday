//
// Created by aldlss on 2022/7/5.
//

//729. 我的日程安排表 I
//set嵌套pair，感觉还行，二分还更快一点
//看到评论区似乎有个高手用了哈希表
//用特化比较方法实现了检验有无重合，好猛

#include<bits/stdc++.h>
using namespace std;
class MyCalendar {
public:
    set<pair<int,int>>timetable;
    MyCalendar():timetable() {

    }

    bool book(int start, int end) {
//        for(auto& [st,ed]:timetable)
//        {
//            if(ed<=start)continue;
//            if(st>=end)break;
//            return false;//要么在前面，要么在后面，否则就不对
//        }
        auto pos=timetable.lower_bound({end,0});
        if(pos==timetable.begin()||(--pos)->second<=start)
        {
            timetable.emplace(start,end);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */