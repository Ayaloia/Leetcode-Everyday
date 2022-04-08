//
// Created by aldlss on 2022/4/8.
//

//简单题，bfs还是好用的，不过没想到dfs也行，学到
//没看到有没有节点的情况，寄，怪不得传指针，就故意挖坑呢

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr)return {};//审题不仔细
        vector<vector<int>>ans;
        vector<int>level;
        int thisLevelNodeSum=1,nextLevelNodeSum=0;
        ans.clear();
        level.clear();
        queue<Node*>waitNode;
        waitNode.push(root);
        while(!waitNode.empty())
        {
            root=waitNode.front();
            waitNode.pop();
            level.push_back(root->val);
            nextLevelNodeSum+=root->children.size();
            for(Node* oneNode:root->children)
                waitNode.push(oneNode);
            --thisLevelNodeSum;
            if(!thisLevelNodeSum)
            {
                ans.push_back(level);
                level.clear();
                thisLevelNodeSum=nextLevelNodeSum;
                nextLevelNodeSum=0;
            }
        }
        return ans;
    }
};