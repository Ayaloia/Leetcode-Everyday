//
// Created by aldlss on 2022/5/1.
//

//1305. 两棵二叉搜索树中的所有元素
//算是比较简单的题，其实我也有考虑过能不能边遍历边排序
//但是想了想感觉似乎不太好实现，有点麻烦了，还是摆了

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans{},num1{},num2{};
        function<void(TreeNode &now,vector<int>&row)>f=[&](TreeNode &now,vector<int>&row)->void {
            if(now.left!=nullptr)f(*now.left,row);
            row.push_back(now.val);
            if(now.right!= nullptr)f(*now.right,row);
        };
        if(root1!=nullptr)f(*root1,num1);//还有不存在的，牛
        if(root2!= nullptr)f(*root2,num2);
        int i=0,j=0;
        while(i<num1.size()&&j<num2.size())
        {
            if(num1[i]<=num2[j])
            {
                ans.push_back(num1[i]);
                ++i;
            }
            else
            {
                ans.push_back(num2[j]);
                ++j;
            }
        }
        for(;i<num1.size();++i)ans.push_back(num1[i]);
        for(;j<num2.size();++j)ans.push_back(num2[j]);
        return ans;
    }
};