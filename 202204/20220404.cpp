//
// Created by aldlss on 2022/4/4.
//

//一眼树状数组，然而我已经忘记了树状数组怎么写，还是现查了一下（
//这个算是比较简单的树状数组，有些难点的属实恐怖，老了老了

#include "bits/stdc++.h"
using namespace std;

class NumArray {
public:
    int* treeHead,n=0;
    NumArray(vector<int>& nums) {
        int* head=new int[nums.size()+1];
        n=nums.size();
        memset(head,0,(n+1)*sizeof(int));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<=n;j+=j&(-j))
            {
                head[j]+=nums[i];
            }
        }
        treeHead=head;
    }

    void update(int index, int val) {
        int delta= sumRange(index,index);
        ++index;//这里也有，又是这种错误...还要注意要放到前面那个的后面
        delta=val-delta;
        for(int i=index;i<=n;i+=i&(-i))
        {
            treeHead[i]+=delta;
        }
    }

    int sumRange(int left, int right) {
        int suml=0,sumr=0;
        ++left;
        ++right;//因为题目的是从0开始的- -
        for(int i=left-1;i;i-=i&(-i))suml+=treeHead[i];
        for(int i=right;i;i-=i&(-i))sumr+=treeHead[i];
        return sumr-suml;
    }

    ~NumArray()
    {
        delete []treeHead;//帮你写了个析构，我觉得我还是比较人道的
    }
};

int main()
{
    vector<int>aya{-1};
    NumArray *a=new NumArray(aya);
    a->sumRange(0,0);
    a->update(0,1);
    return 0;
}
