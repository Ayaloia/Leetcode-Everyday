//
// Created by aldlss on 2022/5/11.
//

//449. 序列化和反序列化二叉搜索树
//还不算难，跟着感觉走算是走对了
//没想到反序列向前找最大的大于值的时候能用二分
//这样说有点像找公共祖先那种，那么应该把二分优化成倍增可以吗？
//不行，终究不是LCA，静态和动态还是有点差别的

#include "bits/stdc++.h"
using namespace std;
// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root== nullptr)return {};
        string ans{};
        if(root->val==0)ans+='0';
        else while(root->val)
        {
            ans+=root->val%10+'0';
            root->val/=10;
        }
        ans+=',';
        if(root->left!= nullptr)
            ans+= serialize(root->left);
        if(root->right!= nullptr)
            ans+= serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        stack<TreeNode*>points{};
        int i=0;
        TreeNode* now= nullptr,*root= nullptr;
        while(i!=data.size())
        {
            int sum=0,mark=1;
            for(;data[i]!=',';++i)
            {
                sum+=(data[i]-'0')*mark;
                mark*=10;
            }
            if(now== nullptr)
                root=now=new TreeNode(sum);
            else
            {
                if(sum<now->val)
                {
                    now->left=new TreeNode(sum);
                    points.push(now);//只有往左走进去的才要进栈
                    now=now->left;
                }
                else
                {
                    while(!points.empty()&&sum>points.top()->val)
                    {
                        now=points.top();
                        points.pop();
                    }
                    now->right=new TreeNode(sum);
                    now=now->right;
                }
            }
            ++i;//比较关键的
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
int main()
{
    Codec a;
    TreeNode* root=new TreeNode{2};
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    auto test=a.serialize(root);
    a.deserialize(test);
    return 0;
}
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;