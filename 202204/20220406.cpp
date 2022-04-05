//
// Created by aldlss on 2022/4/6.
//

#include<bits/stdc++.h>
using namespace std;

//好吧，这道题先用了暴力，自然是TLE了，然后看图是有想到会不会就是求树的直径就可以了
//但是也不是很确定，后面看到评论有人确实求了树的直径才确信确实是可以的
//用的dfs做的求直径，路径也是用比较粗暴简单的方法记录，没想到时间和内存都用得挺少的，挺意外的
//因为重构过，来来回回修改了好几次，所以这个代码真的是有点杂乱了，有点可以体会到所谓的屎山是怎么产生的了- -

class Solution {
public:
    vector<int>ans,tem;
    int maxHigh=0;
    int *head,*arr,*nex;
    void dfs(int x,int high=0,int fa=-1)
    {
        tem.push_back(x);
        for(int i=head[x];i;i=nex[i])
        {
            if(arr[i]==fa)continue;
            dfs(arr[i],high+1,x);
        }
        if(high>maxHigh)
        {
            maxHigh=high;
            ans=tem;
        }
        tem.pop_back();
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        head=new int[n+5];
        arr=new int[n*2+10];
        nex=new int[n*2+10];//注意空间要给够
        memset(head,0,sizeof(int)*(n+5));
        memset(arr,0,sizeof(int)*(n*2+10));
        memset(nex,0,sizeof(int)*(n+5));
        if(n==1)return {0};//我tm直接特判
        int a=0,b=0,len=edges.size();
        int tot=0;
        for(int i=0;i<len;++i)
        {
            a=edges[i][0],b=edges[i][1];
            nex[++tot]=head[a],head[a]=tot,arr[tot]=b;
            nex[++tot]=head[b],head[b]=tot,arr[tot]=a;
        }
        dfs(0);
        a=ans[ans.size()-1];
        ans.clear();
        maxHigh=0;
        dfs(a);//这一块是找树的直径，同时记录路径
        len=ans.size();
        if(len%2)
        {
            tem.push_back(ans[len/2]);
        }
        else
        {
            tem.push_back(ans[len/2]);
            tem.push_back(ans[len/2-1]);
        }
        return tem;
    }
    ~Solution()
    {
        delete []head;
        delete []arr;
        delete []nex;
    }
};

int main()
{
    Solution a;
    vector<vector<int>>aya{{0,1},{1,2},{1,3},{2,4},{3,5},{4,6}};
    a.findMinHeightTrees(7,aya);
    return 0;
}