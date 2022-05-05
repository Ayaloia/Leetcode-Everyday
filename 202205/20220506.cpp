//
// Created by aldlss on 2022/5/6.
//

//933. 最近的请求次数
//简单题，队列秒之，纯属送温暖

#include "bits/stdc++.h"
using namespace std;
class RecentCounter {
public:
    queue<int>request{};
    RecentCounter() {
    }

    int ping(int t) {
        while(!request.empty()&&request.front()<t-3000)
            request.pop();
        request.push(t);
        return request.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */