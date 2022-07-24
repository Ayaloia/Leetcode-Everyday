//
// Created by aldlss on 2022/7/24.
//

//1184. 公交站间的距离

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(destination<start)swap(start,destination);
        return min(accumulate(distance.begin()+start,distance.begin()+destination,0),accumulate(distance.begin(), distance.begin()+start,0)+ accumulate(distance.begin()+destination,distance.end(),0));
    }
};