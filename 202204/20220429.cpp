//
// Created by aldlss on 2022/4/29.
//

//427. 建立四叉树
//不难，没想到写完没改过就A了，看来写的时候思路还是不错的
//不过时间复杂度和空间复杂度令人感叹，看到有二维前缀和优化还是挺敬佩的
//不过这个给的数组其实不是很当人，不便于二维前缀和的开展，看到官方新建了一个vector还是乐的

#include <bits/stdc++.h>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    vector<vector<int>>Wgrid;
    int construct1(int left,int right,int top,int bottom,Node* &now)
    {
        if(left==right&&top==bottom)
        {
            now->isLeaf=true;
            now->val=Wgrid[top][left];
            return now->val;
        }
        now->bottomLeft=new Node;
        now->bottomRight=new Node;
        now->topLeft=new Node;
        now->topRight=new Node;
        int lrMid=(left+right)>>1,tbMid=(top+bottom)>>1;
        int val=construct1(left,lrMid,top,tbMid,now->topLeft)+construct1(lrMid+1,right,top,tbMid,now->topRight)
                +construct1(left,lrMid,tbMid+1,bottom,now->bottomLeft)+construct1(lrMid+1,right,tbMid+1,bottom,now->bottomRight);
        if(val==0||val==4)
        {
            now->isLeaf=true;
            now->val=val/4;
            delete now->bottomRight,delete now->bottomLeft,delete now->topRight,delete now->topLeft;
            now->bottomRight=now->bottomLeft=now->topRight=now->topLeft=nullptr;
            return now->val;
        }
        return 5;
    }
    Node* construct(vector<vector<int>>& grid) {

        Wgrid=grid;
        int n=grid.size();
        Node* ans=new Node;
        construct1(0,n-1,0,n-1,ans);
        return ans;
    }
};