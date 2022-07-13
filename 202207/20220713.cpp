//
// Created by aldlss on 2022/7/13.
//

//735. 行星碰撞
//很愚蠢的遍历，但我不想管了，就这样吧

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool ok= true;
        while(ok&&asteroids.size()>1)
        {
            ok=false;
            int i=0;
            do
            {
                if(asteroids[i]>0&&asteroids[i+1]<0)
                {
                    if(asteroids[i]+asteroids[i+1]>0)
                        asteroids.erase(asteroids.begin()+i+1);
                    else if(asteroids[i]+asteroids[i+1]<0)
                        asteroids.erase(asteroids.begin()+i);
                    else
                        asteroids.erase(asteroids.begin()+i,asteroids.begin()+i+2);
                    ok= true;
                }
            }
            while(++i+1<asteroids.size());
        }
        return asteroids;
    }
};