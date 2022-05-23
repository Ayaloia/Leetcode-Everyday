//
// Created by aldlss on 22-5-23.
//

//675. 为高尔夫比赛砍树
//这题其实还好，先优先队列筛选目的地，然后直接A*走起
//其实A*实现也不难，主要还是想着怎么节省空间和缩短时间了，以及怎么重复利用
//结果为了省那点破空间而且能重复利用，生生地写出了一个bug，也是令人感叹
//只能说A*要理解原理可能不简单，但是要写的话，其实就是多加一个估值而已

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(!forest[0][0])return -1;
        struct point{
            int num;
            int dist;//这个是为了A*算法中计已走步数
            int x,y;
            constexpr bool operator()(const point &lhs, const point &rhs) const{return lhs.num > rhs.num;}
        }temp,now{},target;
        constexpr int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
        int xx=0,yy=0;
        priority_queue<point,vector<point>,point>points{},ax{};//point是决定寻路顺序，ax是用于实现A*
        int m=forest.size(),n=forest[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(forest[i][j]&&forest[i][j]!=1)
                {
                    temp.num=forest[i][j];
                    temp.x=j,temp.y=i;
                    points.emplace(temp);
                }
            }
        }
        vector<vector<int8_t>>vis(m,vector<int8_t>(n));
        int ans=0,sum=0;
        now.x=now.y=0;
        while(!points.empty())
        {
            target=points.top();
            points.pop();
            now.dist=0;
            ax.emplace(now);
            while(!ax.empty())
            {
                do
                {
                    if(ax.empty())
                        return -1;
                    now=ax.top();
                    ax.pop();
                }
                while(vis[now.y][now.x]);
                if(now.y==target.y&&now.x==target.x)break;
                vis[now.y][now.x]=1;
                for(int i=0;i<4;++i)
                {
                    xx=now.x+dx[i],yy=now.y+dy[i];
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&forest[yy][xx]&&!vis[yy][xx])
                    {
                        temp.num=now.dist+abs(target.y-yy)+abs(target.x-xx);
                        temp.x=xx,temp.y=yy;
                        temp.dist=now.dist+1;
                        ax.emplace(temp);
                    }
                }
            }
            if(now.y!=target.y||now.x!=target.x)return -1;
            ans+=now.dist;
            vis=vector<vector<int8_t>>(m,vector<int8_t>(n));
            ax={};
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>>w{{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
    int b=a.cutOffTree(w);
    return 0;
}