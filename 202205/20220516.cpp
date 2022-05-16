//
// Created by aldlss on 2022/5/16.
//

//面试题 04.06. 后继者
//有意思的题目，本来想用function套的，结果发现直接写在外面就可以递归了
//直接在外面递归有一种很奇妙的感觉
//这个指针的使用和判定我觉得也是很巧妙的

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lastNode= nullptr;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)return nullptr;
        TreeNode* ans=nullptr;
        if((ans=inorderSuccessor(root->left,p)))return ans;
        if(lastNode==p)return root;
        lastNode=root;
        return inorderSuccessor(root->right,p);
    }
};