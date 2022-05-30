//
// Created by aldlss on 2022/5/30.
//

//1022. 从根到叶的二进制数之和
//简单题，反倒是折腾编辑器折腾了好久（

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int sum=0) {
        if(!root)return 0;
        sum<<=1;
        sum|=root->val;
        if(!(root->left||root->right))
            return sum;
        return sumRootToLeaf(root->left,sum)+sumRootToLeaf(root->right,sum);
    }
};