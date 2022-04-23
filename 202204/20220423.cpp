//
// Created by aldlss on 2022/4/23.
//

//587. 安装栅栏
//一眼二维凸包，但我还真不会写，上网搜了一下怎么写，算是学到了，竟然还有叉乘的
//疑似空间和时间复杂度都好大，时间的话，估计是我一直push和pop给vector整破防了
//空间的话我是真没想明白，果然还是充分说明了用stl不吸氧死路一条，我觉得还是vector的锅

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int side(vector<int>a,vector<int>b,vector<int>p) {
        b[0]-=a[0],b[1]-=a[1];
        p[0]-=a[0],p[1]-=a[1];
        return b[0]*p[1]-b[1]*p[0];
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size()<=3)return trees;//偷个懒，易得
        sort(trees.begin(),trees.end(),[](vector<int>a,vector<int>b)->bool {
            if(a[0]!=b[0])return a[0]<b[0];
            else return a[1]<b[1];
        });
        vector<vector<int>>ans{};
        ans.push_back(trees[0]),ans.push_back(trees[1]);
        for(int i=2;i<trees.size();++i)
        {
            while(ans.size()>1&&side(*(ans.end()-2),*(ans.end()-1),trees[i])<0)
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        if(ans.size()!=trees.size())//好像加了这个就可以直接防止全是直线的情况了，原本还以为只是小偷懒一下，不得不感叹这算法太智能了啊
        {
            for(int i=trees.size()-2;i>=0;--i)
            {
                while(side(*(ans.end()-2),*(ans.end()-1),trees[i])<0)
                    ans.pop_back();
                ans.push_back(trees[i]);
            }
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>>b{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    a.outerTrees(b);
    return 0;
}