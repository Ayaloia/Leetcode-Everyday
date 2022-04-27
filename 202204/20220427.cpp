//
// Created by aldlss on 2022/4/27.
//

//417. 太平洋大西洋水流问题
//不是很难的题，按平常我oi的习惯的话肯定是能很快秒了
//但是毕竟是在力扣，还是要考虑一下规范点的写法的
//本来想用dfs，结果匿名函数不太能自身调用，写在外面局部变量就不好传过去
//最后只好用bfs，bfs是有点不好写，还是bfs+tuple，还是比较有意思的
//毕竟tuple我也不是很熟，tie这个用法还忘了（

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        const int dx[4]{-1,0,1,0},dy[4]{0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n));
        vector<vector<int>>ans{};
        queue<tuple<int,int,int>>points{};
        for(int i=0;i<m;++i)//1太平洋，2大西洋
            points.push(make_tuple(i,0,1)),points.push(make_tuple(i,n-1,2));
        for(int i=0;i<n;++i)
            points.push(make_tuple(0,i,1)),points.push(make_tuple(m-1,i,2));
        while(!points.empty())
        {
            auto point=points.front();
            points.pop();
            int y,x,flag;
            tie(y,x,flag)=point;
            if(vis[y][x]&flag)continue;
            vis[y][x]|=flag;
            if(vis[y][x]==3)
                ans.push_back({y,x});
            for(int i=0;i<=3;++i)//这里忘加等号，我谔谔
            {
                int yy=y+dy[i],xx=x+dx[i];
                if(yy>=0&&xx>=0&&yy<m&&xx<n&&heights[yy][xx]>=heights[y][x]&&!(vis[yy][xx]&flag))
                    points.push(make_tuple(yy,xx,flag));
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>>w{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    a.pacificAtlantic(w);
}